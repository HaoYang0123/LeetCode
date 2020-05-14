//Leetcode 1444
//动态规划，时间复杂度O(N*M*(N+M)*K)

class Solution {
public:
    int n, m, MOD;
    int ways(vector<string>& pizza, int k) {
        n = pizza.size();
        m = pizza[0].length();
        MOD = 1000000007;
        vector<vector<int>> apple_num(n, vector<int>(m,0));
        //apple_num[i][j]表示从(i,j)至右下角的子矩阵的苹果数量
        for(int i=n-1;i>=0;--i) {
            vector<int> row_num(m, 0);
            row_num[m-1] = (pizza[i][m-1] == 'A' ? 1 : 0);
            for(int j=m-2; j>=0; --j) row_num[j] = row_num[j+1] + (pizza[i][j] == 'A' ? 1 : 0);
            if(i == n-1) apple_num[i] = row_num;
            else{
                for(int j=0;j<m;++j) apple_num[i][j] = apple_num[i+1][j] + row_num[j];
            }
        }
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(m, vector<long long>(k, -1)));
        return dfs(0, 0, k-1, dp, apple_num);
    }
    
    long long dfs(int i, int j, int k, vector<vector<vector<long long>>> & dp,
           vector<vector<int>> & apple_num) {
        if(dp[i][j][k] != -1) return dp[i][j][k];
        if(n-1-i + m-1-j < k) return 0; //如果总的分割数量小于k，无法分割
        int cur_apple = apple_num[i][j];
        if(cur_apple < k+1) return 0; //如果总的apple数量小于k+1个part，则无法分割
        if(k == 0) return 1;
        long long res = 0;
        for(int newi = i+1; newi < n; ++newi) {
            int new_apple = apple_num[newi][j];
            if(cur_apple == new_apple) continue; //说明切出来的part没有apple，不行
            long long tmp = dfs(newi, j, k-1, dp, apple_num);
            res = (res + tmp) % MOD;
        }
        for(int newj = j+1; newj < m; ++newj) {
            int new_apple = apple_num[i][newj];
            if(cur_apple == new_apple) continue;
            long long tmp = dfs(i, newj, k-1, dp, apple_num);
            res = (res + tmp) % MOD;
        }
        dp[i][j][k] = res % MOD;
        return res % MOD;
    }
};
