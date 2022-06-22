// Leetcode 2304

class Solution {
public:
    int m, n;
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int res = INT_MAX;
        for(int i=0; i<n; ++i) {
            dp[m-1][i] = grid[m-1][i];  //最后一行的cost就是grid的值
        }
        for(int i=0; i<n; ++i) {
            int tmp = dfs(0, i, grid, moveCost, dp);
            res = min(res, tmp);
        }
        return res;
    }
    
    int dfs(int i, int j, vector<vector<int>> & grid, vector<vector<int>> & moveCost, vector<vector<int>> & dp) {
        if(dp[i][j] != -1) return dp[i][j];
        int min_v = INT_MAX;
        for(int k=0; k<n; ++k) {
            int tmp_v = moveCost[grid[i][j]][k] + dfs(i+1, k, grid, moveCost, dp);
            min_v = min(min_v, tmp_v);
        }
        min_v += grid[i][j];
        dp[i][j] = min_v;
        return min_v;
    }
};
