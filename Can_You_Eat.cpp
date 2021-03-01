// Leetcode 1744
//时间复杂度O(M lg N)  (其中M为queries的大小， N为candiesCount的大小)

class Solution {
public:
	vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
		int n = candiesCount.size(), m = queries.size();
		vector<bool> res(m, false);
		vector<long long> cand(n, 0);
		cand[0] = candiesCount[0];
		for (int i = 1; i < n; ++i) {
			cand[i] = cand[i - 1] + (long long)(candiesCount[i]);
		}
		for (int i = 0; i < m; ++i) {
			vector<int> & one = queries[i];
			int type = one[0];
			long long day = (long long)one[1], cap = (long long)one[2];
			long long min_v = day + 1;
			long long max_v = (day + 1) * cap;
			int ind1 = lower_bound(cand.begin(), cand.end(), min_v) - cand.begin();
			int ind2 = lower_bound(cand.begin(), cand.end(), max_v) - cand.begin();
			if (type >= ind1 && type <= ind2) res[i] = true;
		}
		return res;
	}
};
