//Leetcode 1187
//动态规划，时间复杂度为O(N^2)，N为arr1的大小

class Solution {
public:
	int makeArrayIncreasing(vector<int> & arr1, vector<int> & arr2) {
		int n=arr1.size(), m=arr2.size();
		sort(arr2.begin(), arr2.end()); //对arr2从小到大排序
		vector<vector<int>> dp(n+1, vector<int>(n+1,INT_MAX)); //dp[i][j]表示从arr1[0]至arr1[i]，能够换j次的arr1[i]值
		dp[0][0] = arr1[0]; //dp[0][0]表示arr1[0]不置换的最小值，肯定是本身(arr1[0])
		dp[0][1] = arr2[0]; //dp[0][1]表示arr1[0]置换1次的最小值，要置换肯定找arr2中最小的值（因为arr2已经排序，所以是arr2[0]）
		for(int i=1;i<n;++i) {
			if(arr1[i]>dp[i-1][0]) dp[i][0]=min(dp[i][0], arr1[i]); //如果当前值(arr1[i]）比i-1值大，那么dp[i][0]就等于arr1[i]
			for(int j=1;j<=i+1;++j) {
				if(arr1[i]>dp[i-1][j]) { //如果当前值比dp[i-1][j]（即上一个值已经置换了j次）大
					dp[i][j]=min(dp[i][j], arr1[i]); //则arr1[i]不能置换，就等于arr1[i]
					int v = dp[i-1][j-1];
					if(v != INT_MAX) { //当然如果上一个值只置换j-1次也有值，那么arr1[i]需要置换1次
						//置换的值肯定是在arr2中大于dp[i-1][j-1]的最小值
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
