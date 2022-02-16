// Leetcode 300
//动态规划

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);  //dp[i]表示nums[i...]（包含nums[i]）的最长递增子序列
        int res = 0;
        for(int i=n-1; i>=0; --i) {
            int max_v = 0;
            for(int j=i+1; j<n; ++j) {
                if(nums[i] < nums[j]) {
                    max_v = max(max_v, dp[j]);
                }
            }
            dp[i] = max_v + 1;
            res = max(res, dp[i]);
        }
        return res;
    }
};
