package Companies.Rippling;

import java.util.HashMap;
import java.util.Map;

class Cell {
    String rawValue;
    String computedValue;

    public Cell(String rawValue, String computedValue) {
        this.rawValue = rawValue;
        this.computedValue = computedValue;
    }
}

class ExcelSheet {

    private final Map<String, Cell> cells;

    public ExcelSheet() {
        cells = new HashMap<>();
    }

    public void set(String cell, String value) {
        if (value.startsWith("=")) {
            // Handle expressions
            cells.put(cell, new Cell(value, computeExpression(value.substring(1))));
        } else {
            // Raw value
            cells.put(cell, new Cell(value, value));
        }
    }

    public void print() {
        for (Map.Entry<String, Cell> entry : cells.entrySet()) {
            String cell = entry.getKey();
            Cell cellData = entry.getValue();
            System.out.println("Cell: " + cell);
            System.out.println("Raw Value: " + cellData.rawValue);
            System.out.println("Computed Value: " + cellData.computedValue);
            System.out.println();
        }
    }

    private String computeExpression(String expression) {
        String[] tokens = expression.split("\\+");
        int result = 0;

        for (String token : tokens) {
            token = token.trim();

            if (token.startsWith("-")) {
                // Handle negative numbers or subtraction
                result += Integer.parseInt(token);
            } else if (token.matches("[A-Z][0-9]+")) {
                // Reference to another cell
                if (cells.containsKey(token)) {
                    result += Integer.parseInt(cells.get(token).computedValue);
                } else {
                    throw new IllegalArgumentException("Referenced cell " + token + " is not defined.");
                }
            } else {
                result += Integer.parseInt(token);
            }
        }
        return String.valueOf(result);
    }
}

public class ExcelSheetClient {
    public static void main(String[] args) {
        ExcelSheet sheet = new ExcelSheet();

        // Example usage
        sheet.set("A1", "=5+9+-8");
        sheet.set("A2", "5");
        sheet.set("A3", "=A1+5");

        sheet.print();
    }
}
