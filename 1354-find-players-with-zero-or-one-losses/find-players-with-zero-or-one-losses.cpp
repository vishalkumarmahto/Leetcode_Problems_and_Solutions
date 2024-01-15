class Solution {
public:
    map<int,int>mp1;
    map<int,int>mp2;
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
            for(int i=0;i<matches.size();i++)
        {
            mp1[matches[i][0]]++;
            mp2[matches[i][1]]++;
        }
        vector<vector<int>>ans;
        vector<int>temp1;
        for(auto it: mp1)
        {
            if(mp2.find(it.first)==mp2.end()) 
            {
                temp1.push_back(it.first);
            }
//if find function finds the value then it return iterator refering to end of map so if it = returns mp2.end() then our value doesn't exist in mp2 and we add it in list 1(temp1).
        }
        ans.push_back(temp1);
        vector<int>temp2;
        for(auto it: mp2)
        {
// players with only single loss
            if(it.second==1)
            {
                temp2.push_back(it.first);
            }
        }
        ans.push_back(temp2);
        return ans;
    } 
    
};