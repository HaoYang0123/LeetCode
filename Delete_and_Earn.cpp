// Leetcode 740

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<int> dp(n, 0), dp2(n, 0);
        //dp[i]表示从nums[i...]（包含nums[i]）的最大值
        //dp2[i]表示从nums[i...]（不一定包含nums[i]）的最大值
        dp[n-1] = nums[n-1];
        dp2[n-1] = nums[n-1];
        int res = dp[n-1];
        for(int i=n-2; i>=0; --i) {
            if(nums[i]==nums[i+1]) dp[i] = nums[i]+dp[i+1];
            else {
                int j=i+1;
                while(j<n && nums[j]==nums[i]+1) ++j;
                if(j>=n) dp[i] = nums[i];
                else dp[i] = nums[i]+dp2[j];
            }
            dp2[i] = max(dp[i], dp2[i+1]);  //dp2[i]有两种情况：1）包含nums[i]的最大值（dp[i]）；2）不包含nums[i]的最大值（dp2[i+1]）
            res = max(res, dp[i]);
        }
        return res;  // or return dp2[0];
    }
};
