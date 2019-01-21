//Leetcode 980

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int start_i = -1, start_j = -1;
        int end_i = -1, end_j = -1;
        vector<vector<int>> dp(n, vector<int>(m, -1)); //dp[i][j]表示从(i,j)到达(end_i, end_j)的路径数目
        vector<vector<bool>> is_vis(n, vector<bool>(m,false));
        int zero_num = 0;
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                if(grid[i][j]==1) {
                    start_i = i;
                    start_j = j;
                }
                else if(grid[i][j]==2) {
                    end_i = i;
                    end_j = j;
                }
                else if(grid[i][j] == 0) {
                    zero_num++;
                }
            }
        }
        //dp[end_i][end_j] = 1;
        zero_num++;
        int cur_len = 0;
        //cout<<start_i<<"\t"<<start_j<<endl;
        is_vis[start_i][start_j] = true;
        return dfs(grid, start_i, start_j, dp, is_vis, zero_num, cur_len, end_i, end_j);
    }
    int dfs(vector<vector<int>> & grid, int cur_i, int cur_j, vector<vector<int>> & dp, vector<vector<bool>> & is_vis, int zero_num, int & cur_len, int end_i, int end_j) {
        if(cur_i == end_i && cur_j == end_j)  {
            //cout<<cur_len<<"\t"<<zero_num<<endl;
            if(cur_len == zero_num) return 1;
            return 0;
        }
        //if(dp[cur_i][cur_j] != -1) return dp[cur_i][cur_j];
        int r_step[] = {0,0,-1,1};
        int c_step[] = {-1,1,0,0};
        int n = grid.size(), m = grid[0].size();
        int res = 0;
        for(int i=0;i<4;++i) {
            int new_i = cur_i + r_step[i];
            int new_j = cur_j + c_step[i];
            if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= m) continue;
            if(grid[new_i][new_j] == -1) continue;
            if(is_vis[new_i][new_j]) continue;
            //cout<<cur_i<<"\t"<<cur_j<<"\t"<<new_i<<"\t"<<new_j<<endl;
            is_vis[new_i][new_j] = true;
            ++cur_len;
            res += dfs(grid, new_i, new_j, dp, is_vis, zero_num, cur_len, end_i, end_j);
            --cur_len;
            is_vis[new_i][new_j] = false;
        }
        //dp[cur_i][cur_j] = res;
        //cout<<cur_i<<"\t"<<cur_j<<"\t"<<dp[cur_i][cur_j]<<endl;
        return res;
    }
};
