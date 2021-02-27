// Leetcode 1770
//时间复杂度：O(M^2)

class Solution {
public:
	int maximumScore(vector<int>& nums, vector<int>& multipliers) {
		int n = nums.size(), m = multipliers.size();
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MIN));
		dp[0][n] = 0;
		int res = INT_MIN;
		for (int i = 0; i <= m; ++i) {
			for (int j = n; j >= n - m + i; --j) {
				//cout << i << "\t" << j << endl;
				if (i - 1 >= 0) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j] + nums[i - 1] * multipliers[i + n - j - 1]);
				}
				if (j < n) {
					dp[i][j] = max(dp[i][j], dp[i][j + 1] + nums[j] * multipliers[i + n - j - 1]);
				}
			}
			res = max(res, dp[i][n - m + i]);
		}
		return res;
	}
};
