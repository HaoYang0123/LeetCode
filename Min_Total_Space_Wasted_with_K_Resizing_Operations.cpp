// Leetcode 1959

class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        // dp[i][j]表示在nums[i]位置变化，后面还可以变j次的最小值
        int res = dfs(nums, 0, k, dp);
        return res;
    }
    
    int dfs(vector<int> & nums, int i, int k, vector<vector<int>> & dp) {
        if(dp[i][k] != -1) return dp[i][k];
        if(k == 0) {
            int cur_max = INT_MIN;
            for(int j=i; j<nums.size(); ++j) cur_max = max(cur_max, nums[j]);
            int res = 0;
            for(int j=i; j<nums.size(); ++j) res += cur_max - nums[j];
            dp[i][k] = res;
            return res;
        }
        if(nums.size()-i <= k) return 0;  //如果后面的数字数量比k还小，那么相当于所有数字都可以变化
        int res = INT_MAX;
        int cur_max = nums[i];
        int dif = 0;
        for(int j=i+1;j<nums.size();++j) {
            int cur = dfs(nums, j, k-1, dp);
            /*计算dif耗时太高了，用了一个for循环
            int dif2 = 0;
            for(int k=i; k<j; ++k) {
                dif2 += cur_max - nums[k];
            }
            cout<<i<<"\t"<<j<<"\t"<<dif<<"\t"<<dif2<<endl;
            for(int p=i;p<j;++p) cout<<"\t"<<nums[p];
            cout<<endl;
            */
            res = min(res, dif + cur);
            if(nums[j] <= cur_max) dif += cur_max - nums[j];
            else dif += (j-i)*(nums[j] - cur_max);
            cur_max = max(cur_max, nums[j]);
        }
        dp[i][k] = res;
        return res;
    }
};
