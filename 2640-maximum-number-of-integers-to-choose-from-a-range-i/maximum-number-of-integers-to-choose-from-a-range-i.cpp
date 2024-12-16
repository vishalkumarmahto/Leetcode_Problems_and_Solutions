class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // Create a set to mark banned numbers
        unordered_set<int> bannedSet(banned.begin(),banned.end());
        long long sum = 0; // Take cumulative sum
        int count = 0;     // Track count of valid numbers

        // Iterate through 1 to n
        for(int i=1;i<=n;i++){
           if(bannedSet.count(i)) continue; // Skipped banned numbers
           sum+=i; // Add current numbers to the sum
           if(sum>maxSum) break; // stop if sum exceeds maxSum
           count++;   // Increment count of valid numbers
        }
        return count;  // Return the count of valid numbers
    }
};