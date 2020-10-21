//Leetcode 1626

class Solution {
public:
	int bestTeamScore(vector<int>& scores, vector<int>& ages) {
		int n = scores.size();
		vector<pair<int, int>> data(n);
		for (int i = 0; i < n; ++i) {
			data[i] = pair<int, int>(ages[i], scores[i]);
		}
		sort(data.begin(), data.end()); //按照年龄从小到大排序
		//for (int i = 0; i < n; ++i) cout << data[i].first << ":" << data[i].second << endl;
		vector<int> dp(n, 0);
		dp[0] = data[0].second;
		int res = dp[0];
		for (int i = 1; i < n; ++i) {
			int cur_max = 0;
			for (int j = i - 1; j >= 0; --j) {
				if (data[j].first == data[i].first || data[j].second <= data[i].second)
					cur_max = max(cur_max, dp[j]);
			}
			dp[i] = cur_max + data[i].second;
			res = max(res, dp[i]);
		}
		return res;
	}
};
