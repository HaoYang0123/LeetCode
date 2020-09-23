//Leetcode 1594
//动态规划，由于有负数，所以需要用dp_min[i][j]和dp_max[i][j]分别记录从(0,0)走至(i,j)的最小累积乘和最大累积乘
//那么，dp_min[i][j] = min(dp_min[i-1][j]*grid[i][j], dp_max[i-1][j]*grid[i][j], dp_min[i][j-1]*grid[i][j], dp_max[i][j-1]*grid[i][j])，四个数中最小的
//同样，dp_max[i][j] = max(dp_min[i-1][j]*grid[i][j], dp_max[i-1][j]*grid[i][j], dp_min[i][j-1]*grid[i][j], dp_max[i][j-1]*grid[i][j])，四个数中最大的

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int MOD = 1000000007;
        int n = grid.size(), m = grid[0].size();
        vector<vector<long long>> dp_min(n, vector<long long>(m, 0));
        vector<vector<long long>> dp_max(n, vector<long long>(m, 0));
        dp_min[0][0] = dp_max[0][0] = grid[0][0];
        for(int i=1;i<m;++i) dp_min[0][i] = dp_max[0][i] = (dp_min[0][i-1] * (long long)grid[0][i]);
        for(int i=1;i<n;++i) dp_min[i][0] = dp_max[i][0] = (dp_min[i-1][0] * (long long)grid[i][0]);
        for(int i=1;i<n;++i) {
            for(int j=1;j<m;++j) {
                dp_min[i][j] = min(dp_min[i-1][j] * grid[i][j], dp_max[i-1][j] * grid[i][j]);
                dp_min[i][j] = min(dp_min[i][j], min(dp_min[i][j-1] * grid[i][j], dp_max[i][j-1] * grid[i][j]));
                dp_max[i][j] = max(dp_min[i-1][j] * grid[i][j], dp_max[i-1][j] * grid[i][j]);
                dp_max[i][j] = max(dp_max[i][j], max(dp_min[i][j-1] * grid[i][j], dp_max[i][j-1] * grid[i][j]));
            }
        }
        return dp_max[n-1][m-1] >= 0 ? dp_max[n-1][m-1] % MOD : -1;
    }
};
