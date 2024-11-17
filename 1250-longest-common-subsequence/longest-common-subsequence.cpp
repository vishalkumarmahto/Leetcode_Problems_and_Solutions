class Solution {
public:
   
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int>prev(m+1,0),curi(m+1,0);
        for(int j=0;j<=m;j++) prev[j] = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1])  curi[j] = 1 + prev[j-1];
               else curi[j] = max(prev[j], curi[j-1]);
            }
            prev = curi;
        }
        return prev[m];
    }
};