// Leetcode 2248

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int, int> val2num;
        for(int i=0; i<nums.size(); ++i) {
            for(int j=0; j<nums[i].size(); ++j) {
                val2num[nums[i][j]]++;
            }
        }
        vector<int> res;
        for(auto idx=val2num.begin(); idx!=val2num.end(); ++idx) {
            if(idx->second == nums.size()) res.push_back(idx->first);
        }
        return res;
    }
};
