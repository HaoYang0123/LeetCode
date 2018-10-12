//Leetcode 695
//一个二维数组，只包含0或1，计算最大的连通的1的面积（四连通）

class Solution {
public:
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max=0;
        for(int i=0;i<grid.size();++i) {
            for(int j=0;j<grid[0].size();++j) {
                if(grid[i][j]==1) {
                    grid[i][j]=0;
                    int tmp=dfs(grid,i,j);
                    if(tmp>max) max=tmp;
                }
            }
        }
        return max;
    }
    
    int dfs(vector<vector<int>> & grid, int i, int j) {
        int r[4] = {0,0,-1,1};
        int c[4] = {-1,1,0,0};
        int grid_r=grid.size(),grid_c=grid[0].size();
        int res=1;
        for (int k = 0; k < 4; ++k) {
            int ni = i+r[k],nj = j+c[k];
            if(ni>=0 && ni<grid_r && nj>=0 && nj<grid_c) {
                if (grid[ni][nj] == 1) {
                    grid[ni][nj]=0;
                    res+=dfs(grid,ni,nj);
                }
            }
        }
        return res;
    }
};
