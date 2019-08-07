//Leetcode 1147

class Solution {
public:
	unordered_map<char, vector<int>> c2pos;
	int longestDecomposition(string text) {
		for (int i = 0; i < text.length(); ++i) {
			c2pos[text[i]].push_back(i);
		}
		int n = text.length();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		return dfs(text, 0, n - 1, dp);
	}

	bool is_same(string& text, int s1, int e1, int s2, int e2) {
		int i = s1+1, j = s2+1;
		while (i <= e1) {
			if (text[i] != text[j]) return false;
			++i;
			++j;
		}
		return true;
	}

	int dfs(string& text, int i, int j, vector<vector<int>>& dp) {
		if (dp[i][j] != 0) return dp[i][j];
		if (i > j) return 0;
		char firstc = text[i];
		//cout << i << "\t" << j << endl;
		vector<int> all_pos = c2pos[firstc];
		int maxv = 0;
		bool has_same = false;
		for (int t = 0; t < all_pos.size(); ++t) {
			int k = all_pos[t];
			if (k <= i) continue;
			if (k > j) break;
			int str_len = j - k + 1;
			int i_end = i + str_len - 1;
			if (i_end >= k) continue;
			//cout << i << "\t" << i_end << "\t" << k << "\t" << j << endl;
			if (is_same(text, i, i_end, k, j)) {
				has_same = true;
				int cur = dfs(text, i_end + 1, k - 1, dp);
				maxv = max(maxv, cur);
			}
		}
		if (has_same) dp[i][j] = maxv + 2;
		else dp[i][j] = maxv + 1;
		return dp[i][j];
	}
};
