// Leetcode 1706

class Solution {
public:
    int n,m;
    vector<int> findBall(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -2));
        vector<int> res(m, -2);
        for(int i=0;i<m;++i) {
            res[i] = dfs(grid, 0, i, dp);
        }
        return res;
    }
    
    int dfs(vector<vector<int>> & grid, int i, int j, vector<vector<int>> & dp) {
        //cout<<i<<"\t"<<j<<endl;
        if(i == n) return j; //如果是到达最底层，则直接返回第j列
        if(dp[i][j] != -2) return dp[i][j];
        if(grid[i][j] == 1) {
            if(j == m-1 || grid[i][j+1] == -1) return -1;
            int tmp = dfs(grid, i+1, j+1, dp);
            dp[i][j] = tmp;
            return tmp;
        }
        else {
            if(j == 0 || grid[i][j-1] == 1) return -1;
            int tmp = dfs(grid, i+1, j-1, dp);
            dp[i][j] = tmp;
            return tmp;
        }
    }
};
