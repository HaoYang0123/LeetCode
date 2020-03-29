//Leetcode 1391
//BFS搜索


class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(n==1 && m==1) return true;
        vector<vector<bool>> is_vis(n, vector<bool>(m, false));
        int r_step[] = {0,0,-1,1};
        int c_step[] = {1,-1,0,0};
        queue<pair<int,int>> qs;
        qs.push({0,0});
        is_vis[0][0] = true;
        while(!qs.empty()) {
            auto cur_pos = qs.front();
            qs.pop();
            int i = cur_pos.first, j = cur_pos.second;
            for(int k = 0; k < 4; ++k) {
                int newi = i + r_step[k];
                int newj = j + c_step[k];
                if(newi < 0 || newi >= n || newj < 0 || newj >= m) continue;
                if(is_vis[newi][newj]) continue;
                if(!can_go(grid[i][j], grid[newi][newj], k+1)) continue;
                if(newi == n-1 && newj == m-1) return true;
                is_vis[newi][newj] = true;
                qs.push({newi, newj});
            }
        }
        return false;
    }
    
    inline bool can_go(int v1, int v2, int flag) {
        //flag=1向右，=2向左，=3向上，=4向下
        if(flag == 1) {
            if((v1 == 1 || v1 == 4 || v1 == 6) && (v2 == 1 || v2 == 3 || v2 == 5)) return true;
            return false;
        }
        else if(flag == 2) {
            if((v1 == 1 || v1 == 3 || v1 == 5) && (v2 == 1 || v2 == 4 || v2 == 6)) return true;
            return false;
        }
        else if(flag == 3) {
            if((v1 == 2 || v1 == 5 || v1 == 6) && (v2 == 2 || v2 == 3 || v2 == 4)) return true;
            return false;
        }
        else {
            if((v1 == 2 || v1 == 3 || v1 == 4) && (v2 == 2 || v2 == 5 || v2 == 6)) return true;
            return false;
        }
    }
};
