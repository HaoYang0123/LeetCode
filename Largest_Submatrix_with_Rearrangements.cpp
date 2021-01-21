// Leetcode 1727

class Solution {
public:
	int largestSubmatrix(vector<vector<int>>& matrix) {
		int n = matrix.size(), m = matrix[0].size();
		vector<vector<int>> dp(n, vector<int>(m, 0));
		for (int i = 0; i < m; ++i) {
			if (matrix[0][i] == 1) dp[0][i] = 1;
		}
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (matrix[i][j] == 1) dp[i][j] = dp[i - 1][j] + 1;
			}
		}
		int res = 0;
		for (int i = 0; i < n; ++i) {
			vector<int> & ones = dp[i];
			sort(ones.begin(), ones.end());
			for (int j = 0; j < m; ++j) {
				int cur = ones[j] * (m - j);
				res = max(res, cur);
			}
		}
		return res;
	}
};
