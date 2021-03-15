// Leetcode 1781

class Solution {
public:
	int beautySum(string s) {
		int n = s.length();
		vector<vector<int>> prefix(n+1, vector<int>(26, 0)); //记录前缀和
		prefix[1][int(s[0] - 'a')]++;
		for (int i = 1; i < n; ++i) {
			prefix[i + 1] = prefix[i];
			prefix[i + 1][int(s[i] - 'a')]++;
		}
		int res = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) { //从i至j
				res += get_beauty(i, j, prefix);
			}
		}
		return res;
	}



	inline int get_beauty(int i, int j, vector<vector<int>> & prefix) {
		vector<int> & pi = prefix[i];
		vector<int> & pj = prefix[j + 1];
		int max_v = 0, min_v = INT_MAX;
		for (int k = 0; k < 26; ++k) {
			int c = pj[k] - pi[k];
			if (c == 0) continue;
			max_v = max(max_v, c);
			min_v = min(min_v, c);
		}
		return max_v - min_v;
	}
};
