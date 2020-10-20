//Leetcode 1615

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> indg(n, 0);
		vector<vector<int>> graph(n, vector<int>(n, 0));
		for(int i=0;i<roads.size();++i) {
			++indg[roads[i][0]];
			++indg[roads[i][1]];
			graph[roads[i][0]][roads[i][1]] = 1;
			graph[roads[i][1]][roads[i][0]] = 1;
		}
		int res = 0;
		for(int i=0;i<n;++i) {
			for(int j=i+1;j<n;++j) {
				int c = indg[i] + indg[j];
				c -= graph[i][j];
				res = max(res, c);
			}
		}
		return res;
    }
};
