//Leetcode 713
//动态规划

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>> dp(n+1,pair<int,int>(0,1)); //dp[i]表示[i,:]最长的相乘<k的数目，及对应的值
        int res=0;
        if(nums[n-1]<k) {
            dp[n-1].first=1;
            dp[n-1].second=nums[n-1];
            ++res;
        }
        for(int i=n-2;i>=0;--i) {
            int cur = dp[i+1].second * nums[i];
            if(cur<k) {
                dp[i].first=dp[i+1].first+1;
                dp[i].second=cur;
                res+=dp[i].first;
            }
            else {
                cur = nums[i];
                int tmp=0;
                int j=i+1;
                while(cur<k) {
                    ++tmp;
                    cur *= nums[j++];
                }
                dp[i].first = tmp;
                dp[i].second = cur / nums[j-1];
                res+=dp[i].first;
            }
        }
        return res;
    }
};
