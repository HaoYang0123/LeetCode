//Leetcode 1498

class Solution {
public:
    int MOD;
    int numSubseq(vector<int>& nums, int target) {
        MOD = 1000000007;
        sort(nums.begin(), nums.end());
        long long res = 0;
        vector<long long> dp(nums.size()+1, 0); //dp[i] = 2^i % MOD
        dp[0] = 1;
        for(int i=1;i<=nums.size();++i) dp[i] = (dp[i-1] * 2) % MOD;
        for(int i=0;i<nums.size();++i) {
            if(nums[i] > target/2) break;
            auto ind = upper_bound(nums.begin(), nums.end(), target-nums[i]);
            int idx = ind - nums.begin();
            --idx; //找到最后一个索引位置，值<=(target-nums[i])
            res = (res + dp[idx-i]) % MOD;
        }
        return res;
    }
};
