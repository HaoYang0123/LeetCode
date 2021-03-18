// Leetcode 1780

class Solution {
public:
	bool checkPowersOfThree(int n) {
		vector<long long> pow_lst;
		long long cur = 1;
		while (cur <= n) {
			pow_lst.push_back(cur);
			cur *= 3;
		}
		vector<int> dp(n+1, 0);
		dp[0] = 1;
		return dfs(pow_lst, dp, 0, n);
	}

	bool dfs(vector<long long> & pow_lst, vector<int> & dp, int idx, int n) {
		if (dp[n] != 0) return dp[n] == 1;
		bool res = false;
		for (int i = idx; i < pow_lst.size(); ++i) {
			if (pow_lst[i] > n) break;
			bool tmp = dfs(pow_lst, dp, i+1, n - pow_lst[i]);
			if (tmp) {
				res = true;
				break;
			}
		}
		if (res) dp[n] = 1;
		else dp[n] = -1;
		return res;
	}
};
