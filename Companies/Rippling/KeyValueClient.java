package Rippling;

import java.util.HashMap;
import java.util.Stack;

// Transaction class to handle changes
class Transaction {
    private HashMap<String, String> changes;

    public Transaction() {
        this.changes = new HashMap<>();
    }

    public HashMap<String, String> getChanges() {
        return changes;
    }

    public void add(String key, String value) {
        changes.put(key, value);
    }

    public void delete(String key) {
        changes.put(key, null); // Mark key as deleted
    }

    public void merge(HashMap<String, String> parentChanges) {
        for (String key : parentChanges.keySet()) {
            changes.put(key, parentChanges.get(key));
        }
    }
}

class Redis {

    private HashMap<String, String> cache; 
    private Stack<Transaction> transactions; // Composition

    public Redis() {
        cache = new HashMap<>();
        transactions = new Stack<>();
    }

    // Starts a new transaction
    public void begin() {
        transactions.push(new Transaction());
    }

    // Commits the latest transaction
    public void commit() {
        if (transactions.isEmpty()) {
            System.out.println("Error: No active transaction to commit.");
            return;
        }

        Transaction transaction = transactions.pop();
        HashMap<String, String> changes = transaction.getChanges();

        for (String key : changes.keySet()) {
            if (changes.get(key) == null) { // if Value of Key is null that means delete operation
                cache.remove(key);
            } else { // Handle additions/updates
                String value = changes.get(key);
                cache.put(key,value);
            }
        }

        // If nested transactions exist, propagate changes to the parent transaction
        if (!transactions.isEmpty()) {
            transactions.peek().merge(changes);
        }
    }

    // Rolls back the latest transaction
    public void rollback() {
        if (transactions.isEmpty()) {
            System.out.println("Error: No active transaction to rollback.");
            return;
        }
        transactions.pop(); // Discard the latest transaction
    }

    // Adds or updates a key-value pair
    public void add(String key, String value) {
        if (transactions.isEmpty()) {
            cache.put(key, value);
        } else {
            Transaction transaction = transactions.peek();
            transaction.add(key, value);
        }
    }

    // Retrieves a value by its key
    public String get(String key) {
        if (!transactions.isEmpty()) {
            for (int i = transactions.size() - 1; i >= 0; i--) {
                Transaction transaction = transactions.get(i);
                if (transaction.getChanges().containsKey(key)) {
                    return transaction.getChanges().get(key); // Return from the most recent transaction
                }
            }
        }
        return cache.getOrDefault(key, null); // Return from the main cache if not found in transactions
    }

    // Deletes a key-value pair
    public void delete(String key) {
        if (transactions.isEmpty()) {
            cache.remove(key);
        } else {
            transactions.peek().delete(key);
        }
    }
}

public class KeyValueClient {
    public static void main(String[] args) {
        Redis cache = new Redis();

        // Basic add and get
        cache.add("key1", "value1");
        System.out.println("Get key1: " + cache.get("key1")); // Output: value1

        // Start a transaction
        cache.begin();
        cache.add("key2", "value2");
        System.out.println("Get key2 in transaction: " + cache.get("key2")); // Output: value2
        cache.rollback();
        System.out.println("Get key2 after rollback: " + cache.get("key2")); // Output: null

        // Nested transactions
        cache.begin();
        cache.add("key3", "value3");
        cache.begin();
        cache.add("key4", "value4");
        cache.commit(); // Commit inner transaction
        System.out.println("Get key4 after inner commit: " + cache.get("key4")); // Output: value4
        cache.rollback(); // Rollback outer transaction
        System.out.println("Get key3 after outer rollback: " + cache.get("key3")); // Output: null
        System.out.println("Get key4 after outer rollback: " + cache.get("key4")); // Output: null

        // Commit with deletions
        cache.add("key5", "value5");
        cache.begin();
        cache.delete("key5");
        cache.commit();
        System.out.println("Get key5 after deletion commit: " + cache.get("key5")); // Output: null

        // Rollback with no active transaction
        cache.rollback(); // Error: No active transaction to rollback
        cache.commit(); // Error: No active transaction to commit
    }
}
