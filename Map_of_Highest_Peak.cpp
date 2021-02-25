// Leetcode 1765

class Solution {
public:
	vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
		//宽度搜索

		int n = isWater.size(), m = isWater[0].size();
		vector<vector<int>> res(n, vector<int>(m, 0));
		vector<vector<bool>> is_vis(n, vector<bool>(m, false)); // is_vis[i][j]记录(i,j)是否被访问
		queue<pair<int, int>> qs;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (isWater[i][j] == 1) {
					res[i][j] = 0; //有水的地方，高度为0
					qs.push(pair<int, int>(i, j));
					is_vis[i][j] = true;
				}
			}
		}
		int r_step[] = { 0,0,-1,1 };
		int c_step[] = { -1,1,0,0 };
		while (!qs.empty()) {
			pair<int, int> cur_pos = qs.front();
			qs.pop();
			for (int k = 0; k < 4; ++k) { //枚举cur_pos的上、下、左、右
				int new_i = cur_pos.first + r_step[k];
				int new_j = cur_pos.second + c_step[k];
				if (new_i < 0 || new_i >= n) continue;
				if (new_j < 0 || new_j >= m) continue;
				if (is_vis[new_i][new_j]) continue;
				res[new_i][new_j] = res[cur_pos.first][cur_pos.second] + 1;
				qs.push(pair<int, int>(new_i, new_j));
				is_vis[new_i][new_j] = true;
			}
		}
		return res;
	}
};
