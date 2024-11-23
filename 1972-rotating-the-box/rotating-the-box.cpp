class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> result(n, vector<char>(m));

        // transpose
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = box[j][i];
            }
        }
        for (vector<char>& row : result) {
            reverse(row.begin(), row.end());
        }
        for (int j = 0; j < m; j++) {
            int spaceBottomRow = n-1;
            for (int i = n - 1; i >= 0; i--) {
               if(result[i][j]=='*'){
                spaceBottomRow = i-1;
                continue;
               }
               if(result[i][j]=='#'){
                result[i][j] = '.';
                result[spaceBottomRow][j] = '#';
                spaceBottomRow--;
               }
            }
        }
        return result;
    }
};