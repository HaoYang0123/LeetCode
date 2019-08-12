//Leetcode 1155
//动态规划

class Solution {
public:
    int MOD;
    int numRollsToTarget(int d, int f, int target) {
        MOD = 1000000007;
        vector<vector<int>> dp(d+1, vector<int>(target+1, -1));
        dp[d][0] = 1;
        for(int i=1;i<=target;++i) dp[d][i] = 0;
        return dfs(0, f, target, dp);
    }
    
    int dfs(int i, int f, int v, vector<vector<int>> & dp) {
        if(dp[i][v] != -1) return dp[i][v];
        int res = 0;
        for(int j=1;j<=f;++j) {
            int newv = v-j;
            if(newv < 0) break;
            res = (res + dfs(i+1, f, newv, dp)) % MOD;
        }
        dp[i][v] = res;
        return res;
    }
};
