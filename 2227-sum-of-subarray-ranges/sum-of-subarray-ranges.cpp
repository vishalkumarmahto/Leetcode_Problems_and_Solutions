class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        long sum = 0;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {   int maxEl= arr[i], minEl = arr[i];
            for(int j=i;j<n;j++){
                maxEl = max(maxEl,arr[j]);
                minEl = min(minEl,arr[j]);
                sum += maxEl - minEl;
            }
        }
        return sum;
    }
};