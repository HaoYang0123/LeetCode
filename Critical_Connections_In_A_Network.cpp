//Leetcode 1192

class Solution {
public:
	vector<vector<int>> ret;
	vector<vector<int>> graph;
	vector<int> index;
	vector<vector<int>> criticalConnections(int n, vector<vector<int>> & connections) {
		graph.resize(n);
		index.resize(n);
		for(int i=0;i<n;++i) index[i] = -1;
		for(int i=0;i<connections.size();++i) {
			int n1 = connections[i][0];
			int n2 = connections[i][1];
			graph[n1].push_back(n2);
			graph[n2].push_back(n1);
		}
		dfs(0, -1, 1);
		return ret;
	}

	int dfs(int node, int pre, int deep) {
		if(index[node] != -1) return index[node];
		index[node] = deep;
		int r=INT_MAX;
		for(int i=0;i<graph[node].size();++i) {
			int n=graph[node][i];
			if(n != pre && index[n] < index[node]) {
				int v=dfs(n, node, deep+1);
				if(v > index[node]) {
					vector<int> l(2, 0);
					l[0] = node;
					l[1] = n;
					ret.push_back(l);
				}
				r = min(r, v);
			}
		}
		return r;
	}
};
