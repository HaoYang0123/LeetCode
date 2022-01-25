// Leetcode 2150

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> v2c;
        for(int i=0; i<nums.size(); ++i) v2c[nums[i]]++;
        vector<int> res;
        for(int i=0; i<nums.size(); ++i) {
            if(v2c[nums[i]] == 1) {
                auto idx1 = v2c.find(nums[i]-1);
                auto idx2 = v2c.find(nums[i]+1);
                if(idx1 == v2c.end() && idx2 == v2c.end()) 
                    res.push_back(nums[i]);
            }
        }
        return res;
    }
};
