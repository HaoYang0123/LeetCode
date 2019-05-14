//Leetcode 1042
//递归查找，查找到直接保存结果并返回（否则会超时）

class Solution {
public:
  bool flag;
  vector<int> g_res;
  vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
		vector<int> res(N, 0);
		vector<vector<int>> edges(N + 2);
		for(int i=0;i<paths.size();++i) {
			int a=paths[i][0]-1, b=paths[i][1]-1; //a<b
			if(a>b) {
				int tmp = a;
				a = b;
				b = tmp;
			}
			edges[b].push_back(a);
		}
		dfs(0, res, edges);
		return g_res;
    }
	
	void dfs(int i, vector<int> & res, vector<vector<int>> & edges) {
		if(flag) return;
		if(i>=res.size()) { 
			flag = true;
			g_res = res;
			return;
		}
		vector<int> type(5, 0);
		vector<int> in_node = edges[i];
		for(int j=0;j<in_node.size();++j) {
			int t = res[in_node[j]];
			type[t] = 1;
		}
		for(int j=1;j<5;++j) {
			if(type[j] == 1) continue;
			res[i] = j;
			dfs(i+1, res, edges);
		}
	}
};
