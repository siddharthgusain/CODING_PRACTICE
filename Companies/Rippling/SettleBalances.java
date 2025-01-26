package Companies.Rippling;

import java.util.*;

public class SettleBalances {
    private static List<String> settleDebtsNonOptimal(List<String[]> transactions) {
        // Map to store net balances
        Map<String, Integer> balances = new HashMap<>();

        // Calculate net balances
        for (String[] transaction : transactions) {
            String from = transaction[0];
            String to = transaction[1];
            int amount = Integer.parseInt(transaction[2]);

            balances.put(from, balances.getOrDefault(from, 0) - amount);
            balances.put(to, balances.getOrDefault(to, 0) + amount);
        }

        // Split into debtors and creditors
        List<String[]> debtors = new ArrayList<>();
        List<String[]> creditors = new ArrayList<>();

        for (Map.Entry<String, Integer> entry : balances.entrySet()) {
            if (entry.getValue() < 0) {
                debtors.add(new String[] { entry.getKey(), String.valueOf(-entry.getValue()) }); // Negative balance
                                                                                                 // converted to
                                                                                                 // positive debt
            } else if (entry.getValue() > 0) {
                creditors.add(new String[] { entry.getKey(), String.valueOf(entry.getValue()) });
            }
        }

        // Settle debts
        List<String> settlements = new ArrayList<>();
        int i = 0, j = 0;

        while (i < debtors.size() && j < creditors.size()) {
            String[] debtor = debtors.get(i);
            String[] creditor = creditors.get(j);

            String from = debtor[0];
            String to = creditor[0];
            int amount = Math.min(Integer.parseInt(debtor[1]), Integer.parseInt(creditor[1]));
            // As we are taking minmum , which ever was minimum will be settled
            settlements.add(from + " pays " + to + " $" + amount);

            // Adjust balances
            debtor[1] = String.valueOf(Integer.parseInt(debtor[1]) - amount);
            creditor[1] = String.valueOf(Integer.parseInt(creditor[1]) - amount);

            // Move to next debtor or creditor if settled
            if (Integer.parseInt(debtor[1]) == 0)
                i++; // either this will be settled
            if (Integer.parseInt(creditor[1]) == 0)
                j++; // or this will be settled
        }

        return settlements;
        // TIME COMP : O(n+m2) n -> Number of transaction , m-> size of balances Map
        // Space comp: 0(n+m)
    }

    public static List<String> settleDebtsWithSorting(List<String[]> transactions) {
        // Map to store net balances
        Map<String, Integer> balances = new HashMap<>();

        // Calculate net balances
        for (String[] transaction : transactions) {
            String from = transaction[0];
            String to = transaction[1];
            int amount = Integer.parseInt(transaction[2]);

            balances.put(from, balances.getOrDefault(from, 0) - amount);
            balances.put(to, balances.getOrDefault(to, 0) + amount);
        }

        // Split into debtors and creditors
        List<String[]> debtors = new ArrayList<>();
        List<String[]> creditors = new ArrayList<>();

        for (Map.Entry<String, Integer> entry : balances.entrySet()) {
            if (entry.getValue() < 0) {
                debtors.add(new String[] { entry.getKey(), String.valueOf(-entry.getValue()) }); // Negative balance
                                                                                                 // converted to
                                                                                                 // positive debt
            } else if (entry.getValue() > 0) {
                creditors.add(new String[] { entry.getKey(), String.valueOf(entry.getValue()) });
            }
        }

        // Sort debtors in ascending order of debt, and creditors in descending order of
        // credit
        debtors.sort((d1, d2) -> Integer.parseInt(d1[1]) - Integer.parseInt(d2[1]));
        creditors.sort((c1, c2) -> Integer.parseInt(c2[1]) - Integer.parseInt(c1[1]));

        // Settle debts
        List<String> settlements = new ArrayList<>();
        int i = 0, j = 0;

        while (i < debtors.size() && j < creditors.size()) {
            String[] debtor = debtors.get(i);
            String[] creditor = creditors.get(j);

            String from = debtor[0];
            String to = creditor[0];
            int amount = Math.min(Integer.parseInt(debtor[1]), Integer.parseInt(creditor[1]));
            // As we are taking the minimum, whichever is minimum will be settled
            settlements.add(from + " pays " + to + " $" + amount);

            // Adjust balances
            debtor[1] = String.valueOf(Integer.parseInt(debtor[1]) - amount);
            creditor[1] = String.valueOf(Integer.parseInt(creditor[1]) - amount);

            // Move to next debtor or creditor if settled
            if (Integer.parseInt(debtor[1]) == 0)
                i++; // This debtor is settled
            if (Integer.parseInt(creditor[1]) == 0)
                j++; // This creditor is settled
        }

        return settlements;
        // TIME COMP : O(n + m log m) where n is the number of transactions and m is the
        // number of unique people (size of the balances map)
        // Space comp: O(n + m) for storing transactions and balances
    }

    public static void main(String[] args) {
        List<String[]> transactions = new ArrayList<>();
        transactions.add(new String[] { "A", "B", "10" }); // A pays B $10
        transactions.add(new String[] { "B", "C", "5" }); // B pays C $5

        List<String> result = settleDebtsWithSorting(transactions);
        for (String settlement : result) {
            System.out.println(settlement);
        }
    }
}
