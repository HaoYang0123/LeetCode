//Leetcode 877
//石子游戏，有一个数组，数组元素是int，A和B两个选手比赛，A选从数组的起点或者终点拿int，B继续拿，获胜条件是谁拿的总和最多，问A是否能够赢得比赛。
//数组元素个数是偶数个，元素和是奇数
//比如：数组[5,3,4,5]，A拿第一个数(5)，剩下的数组为[3,4,5]，然后B无论拿3还是5（当然B会选择当前最好的策略，为5）
//当B拿5后，剩下数组为[3,4]，A肯定会选择较大的4，那么A总共获得5+4=9，而B只获得5+3=8，所以A可以赢得比赛。

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
		int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
		//先计算长度为2的情况：
		int sum=0;
		for(int i=0;i<n-1;++i) {
			sum+=piles[i];
			dp[i][i+1]=max(piles[i],piles[i+1]);
		}
		sum+=piles[n-1];
		//然后计算长度为4，6...,n的情况：
		for(int l=4;l<=n;l+=2) {
			for(int i=0;i+l-1<n;++i) {
				dp[i][i+l-1]=max(piles[i]+min(dp[i+1][i+l-2],dp[i+2][i+l-1]),piles[i+l-1]+min(dp[i+1][i+l-2],dp[i][i+l-3]));
			}
		}
		return dp[0][n-1]>(sum-dp[0][n-1]);
    }
};
