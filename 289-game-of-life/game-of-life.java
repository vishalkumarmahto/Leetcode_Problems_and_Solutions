class Solution {
    public void gameOfLife(int[][] board) {
        int[][] temp = new int[board.length][board[0].length];
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                temp[i][j] = board[i][j];
            }
        }
        int m = temp.length;
        int n = temp[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int h1 = 0, h2 = 0, h3 = 0, h4 = 0, h5 = 0, h6 = 0, h7 = 0, h8 = 0;
                if ((i - 1) >= 0 & (j - 1) >= 0)
                    h1 = temp[i - 1][j - 1];
                if ((i - 1) >= 0 & (j) >= 0)
                    h2 = temp[i - 1][j];
                if ((i - 1) >= 0 & (j + 1) < n)
                    h3 = temp[i - 1][j + 1];
                if ((i) >= 0 & (j - 1) >= 0)
                    h4 = temp[i][j - 1];
                if ((i) < m & (j + 1) < n)
                    h5 = temp[i][j + 1];
                if ((i + 1) < m & (j - 1) >= 0)
                    h6 = temp[i + 1][j - 1];
                if ((i + 1) < m & (j) < n)
                    h7 = temp[i + 1][j];
                if ((i + 1) < m & (j + 1) < n)
                    h8 = temp[i + 1][j + 1];
                int sum = h1 + h2 + h3 + h4 + h5 + h6 + h7 + h8;
                /// original demons
                // System.out.println(sum);

                if (temp[i][j] == 0) {
                    if (sum == 3)
                        board[i][j] = 1;
                } else if (temp[i][j] == 1) {
                    if (sum < 2 || sum > 3) {
                        board[i][j] = 0;
                    }

                }
            }
        }
    }
}