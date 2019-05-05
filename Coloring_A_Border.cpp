//Leetcode 1034

class Solution {
public:
    int n,m;
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> is_visited(n, vector<int>(m,0));
        dfs(grid, is_visited, r0, c0);
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                if(is_visited[i][j] == 2) grid[i][j] = color;
            }
        }
        return grid;
    }
    
    void dfs(vector<vector<int>> & grid, vector<vector<int>> & is_visited, int i, int j) {
        int num = 0;
        int old_color = grid[i][j];
        int r_step[] = {0,0,-1,1};
        int c_step[] = {-1,1,0,0};
        for(int k=0;k<4;++k) {
            int new_i = i+r_step[k];
            int new_j = j+c_step[k];
            if(new_i<0||new_i>=n) continue;
            if(new_j<0||new_j>=m) continue;
            if(grid[new_i][new_j] != old_color) continue;
            ++num;
            if(is_visited[new_i][new_j] != 0) continue;
        }
        if(num==4) is_visited[i][j] = 1;
        else is_visited[i][j] = 2;
        for(int k=0;k<4;++k) {
            int new_i = i+r_step[k];
            int new_j = j+c_step[k];
            if(new_i<0||new_i>=n) continue;
            if(new_j<0||new_j>=m) continue;
            if(grid[new_i][new_j] != old_color) continue;
            if(is_visited[new_i][new_j] != 0) continue;
            dfs(grid, is_visited, new_i, new_j);
        }
    }
};
