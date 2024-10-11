class Solution {
    public boolean isValidSudoku(char[][] board) {
        // step 1 : initialize boolean matrices for row , column and sub boxes
        boolean[][] rows = new boolean[9][9];
        boolean[][] columns = new boolean[9][9];
        boolean[][] subBoxes = new boolean[9][9];

        // Step 2 : Iterate over each cell in the 9x9 board

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';

                    // Step 3 : Calculate sub-box index
                    int boxIndex = (i / 3) * 3 + (j / 3);

                    // Step 4 : check for duplicates
                    if (rows[i][num] || columns[j][num] || subBoxes[boxIndex][num]) {
                        return false;
                    }

                    rows[i][num] = true;
                    columns[j][num] = true;
                    subBoxes[boxIndex][num] = true;
                }

                // Step 5 : mark the digits as seen

            }
        }
        return true;
    }
}