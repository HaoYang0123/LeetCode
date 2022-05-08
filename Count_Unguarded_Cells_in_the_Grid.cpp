// Leetcode 2257

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for(int i=0; i<guards.size(); ++i) {
            grid[guards[i][0]][guards[i][1]] = 2;
        }
        for(int i=0; i<walls.size(); ++i) {
            grid[walls[i][0]][walls[i][1]] = 3;
        }
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j] == 2) {
                    for(int k=j+1; k<n;++k) {
                        if(grid[i][k] == 0) grid[i][k] = 1;
                        else if(grid[i][k] == 2 || grid[i][k] == 3) break;
                    }
                    for(int k=j-1; k>=0; --k) {
                        if(grid[i][k] == 0) grid[i][k] = 1;
                        else if(grid[i][k] == 2 || grid[i][k] == 3) break;
                    }
                    for(int k=i+1; k<m; ++k) {
                        if(grid[k][j] == 0) grid[k][j] = 1;
                        else if(grid[k][j] == 2 || grid[k][j] == 3) break;
                    }
                    for(int k=i-1; k>=0; --k) {
                        if(grid[k][j] == 0) grid[k][j] = 1;
                        else if(grid[k][j] == 2 || grid[k][j] == 3) break;
                    }
                }
            }
        }
        int res = 0;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(grid[i][j] == 0) ++res;
            }
        }
        return res;
    }
};
