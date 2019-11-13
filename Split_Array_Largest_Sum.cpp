//Leetcode 410
//动态规划+分治+减枝，但几乎差点超时
//dp[start][end][m]表示从start至end，分割m次的结果

class Solution {
public:
	int splitArray(vector<int> & nums, int m) {
		int n=nums.size();
		vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(m+1, LLONG_MAX)));
		vector<long long> cur_sum(n, 0);
		cur_sum[0] = nums[0];
		for(int i=1;i<n;++i) {
			cur_sum[i] = cur_sum[i-1] + nums[i];
		}
		for(int i=0;i<n;++i) {
			for(int j=i;j<n;++j) {
				if(i==0) dp[i][j][1] = cur_sum[j];
				else dp[i][j][1] = cur_sum[j]-cur_sum[i-1];
			}
		}
		return dfs(dp, 0, n-1, m);
	}

	long long dfs(vector<vector<vector<long long>>> & dp, int start, int end, int m) {
		if(dp[start][end][m] != LLONG_MAX) return dp[start][end][m];
		long long res = LLONG_MAX;
		for(int i=start+1;i<=end+2-m;++i) { //
			if(dp[start][i-1][1] >= res) continue;
			long long cur = max(dp[start][i-1][1], dfs(dp, i, end, m-1));
			res = min(res, cur);
		}
		dp[start][end][m] = res;
		return res;
	}
};
