class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int maxScore = 0; // initially
        // sort the tokens

        sort(tokens.begin(), tokens.end());
        int i = 0, j = n - 1;
        int score = 0;
        while (i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i];
                score += 1;
                i++;

                maxScore = max(maxScore, score);
            } else if (score >= 1) {
                power += tokens[j];
                score -= 1;
                j--;
            } else {
                return maxScore;
            }
        }
        return maxScore;
    }
};