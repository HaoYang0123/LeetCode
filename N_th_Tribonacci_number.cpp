//Leetcode 1137

class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n+4, -1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        return dfs(n, dp);
    }
    
    int dfs(int n, vector<int> & dp) {
        if(dp[n] != -1) return dp[n];
        dp[n] = dfs(n-1, dp) + dfs(n-2, dp) + dfs(n-3, dp);
        return dp[n];
    }
};
