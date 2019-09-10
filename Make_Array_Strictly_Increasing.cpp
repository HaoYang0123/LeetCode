//Leetcode 1187

class Solution {
public:
	int makeArrayIncreasing(vector<int> & arr1, vector<int> & arr2) {
		int n=arr1.size(), m=arr2.size();
		sort(arr2.begin(), arr2.end());
		vector<vector<int>> dp(n+1, vector<int>(n+1,INT_MAX)); //dp[i][j]表示从arr1[0]至arr1[i]，能够换j次的arr1[i]值
		dp[0][0] = arr1[0];
		dp[0][1] = arr2[0];
		for(int i=1;i<n;++i) {
			if(arr1[i]>dp[i-1][0]) dp[i][0]=min(dp[i][0], arr1[i]);
			for(int j=1;j<=i+1;++j) {
				if(arr1[i]>dp[i-1][j]) {
					dp[i][j]=min(dp[i][j], arr1[i]);
					int v = dp[i-1][j-1];
					if(v != INT_MAX) {
						auto ind = upper_bound(arr2.begin(), arr2.end(), v);
						if(ind != arr2.end()) dp[i][j] = min(dp[i][j], *ind);
					}
				}
				else if (dp[i-1][j-1] != INT_MAX) {
					int v = dp[i-1][j-1];
					auto ind = upper_bound(arr2.begin(), arr2.end(), v);
					if(ind != arr2.end()) dp[i][j] = min(dp[i][j], *ind);
				}
			}
		}
		for(int j=0;j<=n;++j) {
			if(dp[n-1][j] != INT_MAX) return j;
		}
		return -1;
	}
};
