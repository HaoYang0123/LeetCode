// Leetcode 1722

class Solution {
public:
	int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
		int n = source.size();
		vector<unordered_set<int>> edges(n, unordered_set<int>());
		for (int i = 0; i < allowedSwaps.size(); ++i) {
			edges[allowedSwaps[i][0]].insert(allowedSwaps[i][1]);
			edges[allowedSwaps[i][1]].insert(allowedSwaps[i][0]);
		}
		unordered_set<int> is_vis;
		for (int i = 0; i < n; ++i) is_vis.insert(i);
		int res = 0;
		while (!is_vis.empty()) {
			int ind = *is_vis.begin();
			is_vis.erase(ind);
			vector<int> sub_graph;
			sub_graph.push_back(ind);
			dfs(edges, ind, is_vis, sub_graph);  //在图中找一个子图
			unordered_map<int, int> s1, s2; //在子图中将source和target对应元素加入至s1和s2中
			for (int i = 0; i < sub_graph.size(); ++i) {
				s1[source[sub_graph[i]]]++;
				s2[target[sub_graph[i]]]++;
			}
			// 如果s1和s2元素完全相同，相当于子图中任意两个位置可以相互交换，则编辑距离为0
			for (auto vind = s1.begin(); vind != s1.end(); vind++) {
				int v1 = vind->second;
				auto vind2 = s2.find(vind->first);
				int v2 = 0;
				if (vind2 != s2.end()) v2 = vind2->second;
				res += max(0, v1 - v2);
			}
		}
		return res;
	}

	void dfs(vector<unordered_set<int>>& edges, int start, unordered_set<int> & is_vis, vector<int> & sub_graph) {
		unordered_set<int> & out = edges[start];
		for (auto ind = out.begin(); ind != out.end(); ++ind) {
			if (is_vis.find(*ind) == is_vis.end()) continue;
			is_vis.erase(*ind);
			sub_graph.push_back(*ind);
			dfs(edges, *ind, is_vis, sub_graph);
		}
	}
};
