package Rippling;

public class CountIslands {

    // Directions for moving up, down, left, and right
    private static final int[] rowDirections = {-1, 1, 0, 0};
    private static final int[] colDirections = {0, 0, -1, 1};

    // Method to count the number of islands
    public static int countIslands(char[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0) {
            return 0;
        }
        
        int rowCount = grid.length;
        int colCount = grid[0].length;
        int islandCount = 0;

        // Traverse each cell of the grid
        for (int row = 0; row < rowCount; row++) {
            for (int col = 0; col < colCount; col++) {
                if (grid[row][col] == '1') {  // Found an unvisited land cell
                    islandCount++;  // Increment island count
                    dfs(grid, row, col, rowCount, colCount);  // Mark the whole island as visited
                }
            }
        }
        return islandCount;
    }

    // Depth-First Search (DFS) to mark all connected land cells of an island
    private static void dfs(char[][] grid, int row, int col, int rowCount, int colCount) {
        // Check for out of bounds or water ('0') cell
        if (row < 0 || col < 0 || row >= rowCount || col >= colCount || grid[row][col] == '0') {
            return;
        }

        // Mark the current cell as visited by changing it to '0'
        grid[row][col] = '0';

        // Explore all 4 directions (up, down, left, right)
        for (int i = 0; i < 4; i++) {
            int newRow = row + rowDirections[i];
            int newCol = col + colDirections[i];
            dfs(grid, newRow, newCol, rowCount, colCount);
        }
    }

    public static void main(String[] args) {
        char[][] grid = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'}
        };

        System.out.println("Number of islands: " + countIslands(grid));  // Output: 1
    }
}
