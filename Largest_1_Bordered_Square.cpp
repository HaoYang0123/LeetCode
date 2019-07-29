//Leetcode 1139
//O(N^4)，暴力枚举+剪枝

class Solution {
public:
	bool check(vector<vector<int>>& grid, int i, int j, int w) {
		for (int r = i; r < i + w; ++r) {
			if (grid[r][j] == 0 || grid[r][j + w - 1] == 0) return false;
		}
		for (int c = j; c < j + w; ++c) {
			if (grid[i][c] == 0 || grid[i + w - 1][c] == 0) return false;
		}
		return true;
	}
	int largest1BorderedSquare(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		int res = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] == 0) continue;
				int width = min(n - i, m - j);
				for (int w = width; w >= 1; --w) {
					if (w * w <= res) break;
					if (check(grid, i, j, w)) {
						res = w * w;
						break;
					}
				}
			}
		}
		return res;
	}
};
