class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int i = 0;
        for(int j=1;j<arr.size();j++){
            if(arr[j]!=arr[i]){
                arr[i+1]=arr[j];
                i++;
            }

        }
        return i+1;
    }
};