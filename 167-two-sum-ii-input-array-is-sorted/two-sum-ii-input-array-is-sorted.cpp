class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
          unordered_map<int,int> mpp;
          int n = numbers.size();
          for(int i=0;i<n;i++){
            int num = numbers[i];
            int more = target - num;
            if(mpp.find(more)!=mpp.end()){
                return {mpp[more]+1,i+1};
            }
            mpp[num] = i;
          }
          return {-1,-1};
    }
};