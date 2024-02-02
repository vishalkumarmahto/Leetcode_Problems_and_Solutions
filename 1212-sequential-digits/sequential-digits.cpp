class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
       vector<int> result;
        for(int i=1;i<=9;i++){
            int num = i;
            int nextDigit = i + 1;
            while(num<=high && nextDigit<=9){
                num = num * 10 + nextDigit;
                if(low<=num && num<=high) result.push_back(num);
                ++nextDigit;
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};