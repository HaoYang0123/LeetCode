//Leetcode 1220
//动态规划方法，先将问题转化为有向图
//dp[i][j]记录从第i个结点，路径长度为j的个数
//dp[i][1]=1，因为路径长度为1只有自己
//有动态规划转移方程：dp[i][j]=dp[k][j-1] for every edge (i,k)

class Solution {
public:
	int MOD;
	int countVowelPermutation(int n) {
		MOD = 1000000007;
		int count = 5;
		vector<vector<int>> edges(count, vector<int>());
		edges[0].push_back(1); //a->e
		edges[1].push_back(0); //e->a
		edges[1].push_back(2); //e->i
		edges[2].push_back(0); //i->a
		edges[2].push_back(1); //i->e
		edges[2].push_back(3); //i->o
		edges[2].push_back(4); //i->u
		edges[3].push_back(2); //o->i
		edges[3].push_back(4); //o->u
		edges[4].push_back(0); //u->a

		vector<vector<int>> dp(count, vector<int>(n+1, 0));
		for(int i=0;i<count; ++i) dp[i][1] = 1;
		int res = 0;
		for(int i=0; i<count; ++i) {
			int tmp = dfs(n, i, edges, dp);
			res = (res + tmp) % MOD;
		}
		return res;
	}

	int dfs(int n, int start, vector<vector<int>> & edges, vector<vector<int>> & dp) {
		if(dp[start][n] != 0) return dp[start][n];
		vector<int> & nodes = edges[start];
		int res = 0;
		for(int i=0;i<nodes.size();++i) {
			int tmp = dfs(n-1, nodes[i], edges, dp);
			res = (res + tmp) % MOD;
		}
		dp[start][n] = res;
		return res;
	}
};
