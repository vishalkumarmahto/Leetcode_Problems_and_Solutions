class Solution {
public:
    int lcs(string text1, string text2)
{
	
	int n = text1.size(), m = text2.size();
    vector<int>prev(m+1,0),curi(m+1,0);
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1])  curi[j] = 1 + prev[j-1];
               else curi[j] = max(prev[j], curi[j-1]);
            }
            prev = curi;
        }
        return prev[m];
}

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        return n+m-2*lcs(word1,word2);
    }
};