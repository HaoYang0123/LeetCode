// Leetcode 2097
//欧拉回路

class Solution {
public:
	deque<int> path;

	void dfs(int cur, unordered_map<int, vector<int>> & graph, unordered_map<int, int> & v2out) {
		while (v2out[cur]) {
			int newNode = graph[cur][v2out[cur] - 1];
			v2out[cur]--;
			dfs(newNode, graph, v2out);
		}
		path.push_front(cur);
	}

	vector<vector<int>> validArrangement(vector<vector<int>> & pairs) {
		unordered_map<int, int> v2in, v2out;
		unordered_map<int, vector<int>> graph;
		for (int i = 0; i < pairs.size(); ++i) {
			int s = pairs[i][0], e = pairs[i][1];
			v2out[s]++;
			v2in[e]++;
			graph[s].push_back(e);
		}
		int start = v2out.begin()->first;
		for (auto ind = v2out.begin(); ind != v2out.end(); ++ind) {
			int inn = v2in[ind->first];
			int outn = ind->second;
			if (inn < outn) {
				start = ind->first;
			}
		}
		//cout << start << endl;
		vector<vector<int>> res;
		dfs(start, graph, v2out);
        for(int i=0; i<path.size()-1; ++i) res.push_back({path[i], path[i+1]});
		return res;
	}
};
