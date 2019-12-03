//Leetcode 1278
//O(N^4)时间复杂度

class Solution {
public:
	int palindromePartition(string s, int k) {
		int n = s.length();
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k+1)));
		vector<vector<int>> dp2(n, vector<int>(n, 0));
		for(int i=0;i<n;++i) {
			for(int j=i+1;j<n;++j) {
				int mid = (i+j-1)/2, par_num = 0;
				for(int p=i;p<=mid;++p) {
					if(s[p] != s[j-p+i]) ++par_num;
				}
				dp2[i][j] = par_num;
				dp[i][j][1] = par_num;
			}
		}
		for(int i=0;i<n;++i) {
			for(int j=i+1;j<n;++j) {
				for(int p=2;p<=min(k, j-i+1);++p) {
					int min_res = INT_MAX;
					for(int j2=i+p-2;j2<j;++j2) {
						min_res = min(min_res, dp[i][j2][p-1] + dp2[j2+1][j]);
					}
					dp[i][j][p] = min_res;
				}
			}
		}
		return dp[0][n-1][k];
	}
};
