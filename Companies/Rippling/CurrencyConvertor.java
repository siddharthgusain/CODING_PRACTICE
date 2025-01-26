package Companies.Rippling;

import java.util.*;

class Edge {
    String to; // To Currency String
    double rate; // Rate of Conversion

    Edge(String to, double rate) {
        this.to = to;
        this.rate = rate;
    }
}

class Pair {
    String currency;
    double rate;

    Pair(String currency, double rate) {
        this.currency = currency;
        this.rate = rate;
    }
}

public class CurrencyConvertor {
    private static double findConversionRate(List<String[]> rates, String[] query) {
        Map<String, List<Edge>> graph = new HashMap<>(); // AS Key can be of Any Data Type , So Lookup is O(1)
        // If we take Array of Array list -> We have to search of Key that is String so
        // O(n) complexity
        for (String[] rate : rates) {
            String from = rate[0];
            String to = rate[1];
            double value = Double.parseDouble(rate[2]);
            graph.putIfAbsent(from, new ArrayList<>());
            graph.putIfAbsent(to, new ArrayList<>());

            graph.get(from).add(new Edge(to, value));
            graph.get(to).add(new Edge(from, 1 / value));
        }

        String source = query[0];
        String destination = query[1];

        if (!graph.containsKey(source) || !graph.containsKey(destination)) {
            return -1;
        }

        Queue<Pair> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>(); // As Node is String type not integer like array indexes
        queue.add(new Pair(source, 1));

        while (!queue.isEmpty()) { // BFS Algorithm
            Pair pair = queue.poll();
            String currency = pair.currency; // Currency String
            double rate = pair.rate; // Rate

            if (currency.equals(destination)) {
                return rate;
            }

            if (visited.contains(currency)) {
                continue;
            }

            visited.add(currency);

            for (Edge edge : graph.get(currency)) {
                if (!visited.contains(edge.to)) {
                    queue.add(new Pair(edge.to, rate * edge.rate));
                }
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        List<String[]> rates = new ArrayList<>();
        rates.add(new String[] { "USD", "JPY", "110" });
        rates.add(new String[] { "USD", "AUD", "1.45" });
        rates.add(new String[] { "JPY", "GBP", "0.0070" });

        String[] query = { "GBP", "AUD" };
        double result = findConversionRate(rates, query);

        if (result == -1) {
            System.out.println("No conversion rate found");
        } else {
            System.out.println("Conversion Rate is " + String.format("%.2f", result));
        }
    }
}
