//Leetcode 1269
//动态规划：dp[i][j]存储从起点0至i位置，经过j步的数量
//注意到样例规模的数组长度(10^6)远大于步数(500)，但是步数限制，肯定到达不了比steps位置更远的位置

class Solution {
public:
	int numWays(int steps, int arrLen) {
		int MOD = 1000000007;
		int n = arrLen;
		if(steps+1<n) n = steps+1; //如果n比steps+1，则步数限制，最远距离最多是steps，所以开数组steps+1（+1是限止数组越界）
		vector<vector<long long>> dp(n, vector<long long>(steps + 1, 0)); //使用long long存储，防止相加超过int表示的最大范围
		dp[0][0] = 1;
		for(int j=1;j<steps+1;++j) {
			for(int i=0;i<n;++i) {
				if(i-1 >= 0) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
				if(i+1 < n) dp[i][j] = (dp[i][j] + dp[i+1][j-1]) % MOD;
				dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
			}
		}
		return dp[0][steps];
	}
};
