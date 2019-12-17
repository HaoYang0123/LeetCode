//Leetcode 1289

class Solution {
public:
	int minFallingPathSum(vector<vector<int>> & arr) {
		int n = arr.size(); //arr.size()==arr[0].size()
		vector<vector<int>> dp(n, vector<int>(n, INT_MAX)); //dp[i][j]表示从第0行走到(i,j)的最小和
		for(int i=0;i<n;++i) dp[0][i] = arr[0][i];
		for(int i=1;i<n;++i) {
			for(int j=0;j<n;++j) {
				for(int k=0;k<n;++k) {
					if(k == j) continue;
					dp[i][j] = min(dp[i][j], dp[i-1][k]);
				}
				dp[i][j] += arr[i][j];
			}
		}
		int res = INT_MAX;
		for(int i=0;i<n;++i) res = min(res, dp[n-1][i]);
		return res;
	}
};
