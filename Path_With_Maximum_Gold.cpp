//Leetcode 1219
//深度搜索

class Solution {
public:
	int n, m;
	int getMaximumGold(vector<vector<int>> & grid) {
		int res = 0;
		n = grid.size();
		m = grid[0].size();
		for(int i=0;i<n;++i) {
			for(int j=0;j<m;++j) {
				if(grid[i][j] == 0) continue;
				res = max(res, dfs(grid, i, j));
			}
		}
		return res;
	}

	int dfs(vector<vector<int>> & grid, int r, int c) {
		int r_step[] = {0, 0, 1, -1};
		int c_step[] = {1, -1, 0, 0};
		int res = grid[r][c], max_v = 0;
		grid[r][c] = 0;
		for(int i=0;i<4;++i) {
			int new_r = r + r_step[i];
			int new_c = c + c_step[i];
			if(new_r < 0 || new_r >= n) continue;
			if(new_c < 0 || new_c >= m) continue;
			if(grid[new_r][new_c] == 0) continue;
			max_v = max(max_v, dfs(grid, new_r, new_c));
		}
		grid[r][c] = res;
		return res + max_v;
	}
};
