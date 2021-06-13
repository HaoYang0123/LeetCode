// Leetcode 1863

class Solution {
public:
    int sum;
    int subsetXORSum(vector<int>& nums) {
        sum = 0;
        dfs(nums, 0, 0);
        return sum;
    }
    
    void dfs(vector<int>& nums, int i, int cur) {
        if(i == nums.size()) {
            sum += cur;
            return;
        }
        dfs(nums, i+1, cur);
        cur ^= nums[i];
        dfs(nums, i+1, cur);
    }
};
