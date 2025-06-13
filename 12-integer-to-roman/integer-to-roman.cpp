class Solution {
public:
    string intToRoman(int num) {
        string s = "";
        int nums[] = {1, 5, 10, 50, 100, 500, 1000};
        char rom[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        for(int index = 6; index >= 0; index--) {
            if (num / (nums[index]) == 4) {
                s += rom[index];
                s += rom[index + 1];
            } else if (num / (nums[index]) == 9) {
                s += rom[index];
                s += rom[index + 2];
            } else if ((index - 1) >= 0 && ((num % nums[index]) / nums[index - 1] == 4)) {
                continue;
            } else {
                s += string(num / nums[index], rom[index]);
            }
            num = num % nums[index];
        }
        return s;
    }
};