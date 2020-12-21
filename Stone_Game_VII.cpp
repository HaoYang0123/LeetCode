// Leetcode 1690

class Solution {
public:
	int stoneGameVII(vector<int> & stones) {
		int n = stones.size();
		vector<vector<int>> dp(n, vector<int>(n, -1));
		int cur_sum = 0;
		for (int i = 0; i < n; ++i) cur_sum += stones[i];
		int res = dfs(stones, 0, n - 1, dp, cur_sum);
		return res;
	}

	int dfs(vector<int> & stones, int i, int j, vector<vector<int>> & dp, int cur_sum) {
		if (i > j) return 0;
		if (i == j) return 0;
		if (i + 1 == j) return max(stones[i], stones[j]);
		if (dp[i][j] != -1) return dp[i][j];
		int d1 =  (cur_sum - stones[i]) - dfs(stones, i + 1, j, dp, cur_sum - stones[i]);
		int d2 = (cur_sum - stones[j]) - dfs(stones, i, j - 1, dp, cur_sum - stones[j]);
		dp[i][j] = max(d1, d2);
		return dp[i][j];
	}
};
