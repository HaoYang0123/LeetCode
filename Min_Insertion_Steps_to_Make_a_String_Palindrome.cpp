//Leetcode 1312

class Solution {
public:
	int minInsertions(string s) {
		int n=s.length();
		vector<vector<int>> dp(n, vector<int>(n, -1));
		return dfs(s, 0, n-1, dp);
	}

	int dfs(string & s, int i, int j, vector<vector<int>> & dp) {
		if(i >= j) return 0;
		if(dp[i][j] != -1) return dp[i][j];
		if(s[i] == s[j]) {
			dp[i][j] = dfs(s, i+1, j-1, dp);
			return dp[i][j];
		}
		dp[i][j] = min(1+dfs(s, i, j-1, dp), 1+dfs(s, i+1, j, dp));
		return dp[i][j];
	}
};
