// Leetcode 2295

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> val2pos;
        for(int i=0; i<nums.size(); ++i) {
            val2pos[nums[i]] = i;
        }
        
        for(int i=0; i<operations.size(); ++i) {
            int ori_v = operations[i][0], new_v = operations[i][1];
            nums[val2pos[ori_v]] = new_v;
            val2pos[new_v] = val2pos[ori_v];
        }
        return nums;
    }
};
