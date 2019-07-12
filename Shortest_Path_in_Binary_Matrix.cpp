//Leetcode 1091
//BFS 宽度优化搜索

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>> qs;
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> is_vis(n,vector<int>(m,0)); //is_vis[i][j]表示从(0,0)到达(i,j)的最小步数
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        is_vis[0][0]=1;
        qs.push(pair<int,int>(0,0));
        int r_step[] = {-1,-1,-1,0,0,1,1,1};
        int c_step[] = {-1,0,1,-1,1,-1,0,1};
        while(!qs.empty()) {
            pair<int,int> cur_pos=qs.front();
            qs.pop();
            for(int i=0;i<8;++i) {
                int new_i = cur_pos.first+r_step[i];
                int new_j = cur_pos.second+c_step[i];
                if(new_i<0||new_i>=n) continue;
                if(new_j<0||new_j>=m) continue;
                if(grid[new_i][new_j]==1) continue; //has block
                if(is_vis[new_i][new_j]>=1) continue; //has visited
                if(new_i==n-1 && new_j==m-1) return is_vis[cur_pos.first][cur_pos.second]+1;
                is_vis[new_i][new_j] = is_vis[cur_pos.first][cur_pos.second]+1;
                qs.push(pair<int,int>(new_i, new_j));
            }
        }
        return -1;
    }
};
