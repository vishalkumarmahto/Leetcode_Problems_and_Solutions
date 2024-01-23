class Solution {
public:
    int uniqueChar(vector<string>& arr, unordered_map<int, int> mp, int ind) {
        if (ind < 0)
            return mp.size();

        unordered_map<int, int> mp1 = mp;
        int flag = 1, cnt = 0, cnt1 = 0;

        for (int i = 0; i < arr[ind].size(); i++) {
            if (mp1.count(arr[ind][i])) {
                flag = 0;
                break;
            }
            mp1[arr[ind][i]]++;
        }
        if (flag) {
            cnt += uniqueChar(arr, mp1, ind - 1);
        }
        cnt1 += uniqueChar(arr, mp, ind - 1);

        return max(cnt1, cnt);
    }

    int maxLength(vector<string>& arr) {
        unordered_map<int, int> mp;
        return uniqueChar(arr, mp, arr.size() - 1);
    }
};