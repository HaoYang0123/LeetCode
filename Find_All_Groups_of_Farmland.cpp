// Leetcode 1992

class Solution {
public:
    int n,m;
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n=land.size();
        m=land[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> is_vis(n, vector<bool>(m, false));
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(land[i][j] == 1 and !is_vis[i][j]) {
                    int i2 = i, j2 = j;
                    is_vis[i][j] = true;
                    dfs(land, i, j, is_vis, i2, j2);
                    res.push_back({i,j,i2,j2});
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<int>> & land, int i, int j, vector<vector<bool>> & is_vis, int & i2, int & j2) {
        int r_step[] = {-1,1,0,0};
        int c_step[] = {0,0,-1,1};
        for(int k=0; k<4; ++k) {
            int newi = i + r_step[k];
            int newj = j + c_step[k];
            if(newi < 0 || newi >= n) continue;
            if(newj < 0 || newj >= m) continue;
            if(is_vis[newi][newj]) continue;
            if(land[newi][newj] == 1) {
                is_vis[newi][newj] = true;
                i2 = max(i2, newi);
                j2 = max(j2, newj);
                dfs(land, newi, newj, is_vis, i2, j2);
                //is_vis[newi][newj] = false;
            }
        }
    }
};
