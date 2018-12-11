//Leetcode 892
//O(N^2)

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size(), m = grid[0].size();
        int r[4] = {0,0,-1,1};
        int c[4] = {-1,1,0,0};
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                if(grid[i][j] != 0) {
                    res += (2 + 4*grid[i][j]); //2表示底面积和顶面积，侧面积则为grid[i][j]，因为有4个侧面，所以乘以4
                    for(int k=0;k<4;++k) {
                        int nI = i+r[k], nJ = j+c[k];
                        if(nI >= 0 && nI < n && nJ >= 0 && nJ < m) {
                            res -= min(grid[i][j], grid[nI][nJ]); //将重复计算的面积减去
                        }
                    }
                }
            }
        }
        return res;
    }
};
