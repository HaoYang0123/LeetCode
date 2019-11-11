//Leetcode 1254

class Solution {
public:
	int n,m,res;
	int closedIsland(vector<vector<int>> & grid) {
		n = grid.size();
		m = grid[0].size();
		res = 0;
		for(int i=0;i<n;++i) { //将边界的0处理掉
			if(grid[i][0] == 0) {
				grid[i][0] = 2;
				dfs(i, 0, grid);
			}
			if(grid[i][m-1] == 0) {
				grid[i][m-1] = 2;
				dfs(i, m-1, grid);
			}
		}
		for(int i=0;i<m;++i) { //将边界的0处理掉
			if(grid[0][i] == 0) {
				grid[0][i] = 2;
				dfs(0, i, grid);
			}
			if(grid[n-1][i] == 0) {
				grid[n-1][i] = 2;
				dfs(n-1, i, grid);
			}
		}
		for(int i=1;i<n-1;++i) {
			for(int j=1;j<m-1;++j) {
				if(grid[i][j] == 0) { //其它没处理掉的0，则是island
					++res;
					dfs(i, j, grid);
				}
			}
		}
		return res;
	}

	void dfs(int i,int j, vector<vector<int>> & grid) {
		int r_step[] = {0,0,-1,1};
		int c_step[] = {-1,1,0,0};
		
		for(int k=0;k<4;++k) {
			int new_i = i+r_step[k];
			int new_j = j+c_step[k];
			if(new_i < 0 || new_i >= n) continue;
			if(new_j < 0 || new_j >= m) continue;
			if(grid[new_i][new_j] == 0) {
				grid[new_i][new_j] = 2;
				dfs(new_i, new_j, grid);
			}
		}
	}
};
