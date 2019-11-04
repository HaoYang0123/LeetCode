//Leetcode 1245
//动态规划：dp[i][j]记录从结点i到结点j作为路径中第1条边，枚举后续边的情况，记录最长路径的长度

class Solution {
public:
	int treeDiameter(vector<vector<int>> & edges) {
		int n = edges.size() + 1;
		vector<bool> is_vis(n, false);
		vector<vector<int>> graph(n);
		vector<vector<int>> dp(n);
		for(int i=0;i<edges.size();++i) {
			int s=edges[i][0], e=edges[i][1];
			graph[s].push_back(e);
			graph[e].push_back(s);
			dp[s].push_back(0);
			dp[e].push_back(0);
		}
		int res = 0;
		for(int i=0;i<n;++i) {
			is_vis[i] = true;
			res = max(res, dfs(graph, dp, i, is_vis));
			is_vis[i] = false;
		}
		return res - 1;
	}

	int dfs(vector<vector<int>> & graph, vector<vector<int>> & dp, int start, vector<bool> & is_vis) {
		vector<int> & edges = graph[start];
		int res = 0;
		for(int i=0;i<edges.size();++i) {
			int e = edges[i];
			if(is_vis[e]) continue;
			is_vis[e] = true;
			if(dp[start][i] != 0) res = max(res, dp[start][i]);
			else {
				int cur = dfs(graph, dp, e, is_vis);
				dp[start][i] = cur;
				res = max(res, cur);
			}
			is_vis[e] = false;
		}
		return res + 1;
	}
};
