//Leetcode 1443

class Solution {
public:
	int minTime(int n, vector<vector<int>> & edges, vector<bool> & hasApple) {
		vector<vector<int>> graph(n, vector<int>());
		for (int i = 0; i < edges.size(); ++i) {
			graph[edges[i][0]].push_back(edges[i][1]);
		}
		pair<int, bool> res = dfs(graph, 0, hasApple);
		if (!res.second) return 0;
		return res.first;
	}

	pair<int, bool> dfs(vector<vector<int>> & graph, int cur_root, vector<bool> & hasApple) {
		vector<int> & children = graph[cur_root];
		if (children.size() == 0) { //叶子结点
			return pair<int, bool>(0, hasApple[cur_root]);
		}
		int res = 0;
		bool has_apple = hasApple[cur_root]; //只要当前结点、或者任意子树有苹果，那么就表示有苹果，所需步数等于res
		for (int i = 0; i < children.size(); ++i) { //枚举左、右叶子结点
			pair<int, bool> child_res = dfs(graph, children[i], hasApple);
			if(child_res.second) //如果子树有苹果，才会将所需步数加入res，多加2是因为需要花两步从当前结点走到子树结点
				res += child_res.first + 2;
			has_apple = has_apple || child_res.second;
		}
		if (!has_apple) res = 0;
		return pair<int, bool>(res, has_apple);
	}
};
