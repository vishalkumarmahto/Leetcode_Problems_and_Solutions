class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         
    
    vector<vector<int>> mergedInterval;
    if (intervals.size() == 0) return mergedInterval; // or just return {}

    // Sort intervals based on the start time
    sort(intervals.begin(), intervals.end());

    vector<int> tempInterval = intervals[0];

    for (auto it : intervals) {
        if (it[0] <= tempInterval[1]) { // Fix condition
            tempInterval[1] = max(it[1], tempInterval[1]);
        } else {
            mergedInterval.push_back(tempInterval);
            tempInterval = it;
        }
    }

    // Push the last interval
    mergedInterval.push_back(tempInterval);

    return mergedInterval;
    }
};