//Leetcode 126

class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		wordList.push_back(beginWord);
		int n = wordList.size();
		//unordered_map<string, int> word2index;
		int start = -1, end = -1;
		vector<vector<int>> graph(n, vector<int>());
		for (int i = 0; i < n; ++i) {
			if (wordList[i] == beginWord) start = i;
			if (wordList[i] == endWord) end = i;
			for (int j = 0; j < n; ++j) {
				bool flag = is_edge(wordList[i], wordList[j]);
				if (flag) graph[i].push_back(j);
			}
		}
		if (end == -1) return vector<vector<string>>();
		//write(graph, wordList);
		vector<vector<string>> res;
		vector<vector<int>> dp(n,vector<int>()); //dp[i]表示到达i的前一个结点的集合
		queue<pair<int, int>> qs; //pair[0]表示当前到达的结点，pari[1]表示从start到达当前结点的最小步数
		vector<int> is_vis(n, INT_MAX); //is_vis[i]表示从start到达i的最小步数
		is_vis[start] = 0;
		qs.push(pair<int,int>(start,0));
		while (!qs.empty()) {
			pair<int, int> cur = qs.front();
			//cout << "Queue\t" << cur.first << "\t" << cur.second << endl;
			qs.pop();
			int cur_pos = cur.first, cur_step = cur.second;
			vector<int> new_pos = graph[cur_pos];
			int new_step = cur_step + 1;
			for (int i = 0; i < new_pos.size(); ++i) {
				int new_p = new_pos[i];
				if (is_vis[new_p] < new_step) continue; //说明已经到达了new_p不用考虑
				if (is_vis[new_p] > new_step) qs.push(pair<int, int>(new_p, new_step)); //如果is_vis[new_p]等于new_step，说明到达new_p拥有多条路径，qs已经拥有new_p
				is_vis[new_p] = new_step;
				dp[new_p].push_back(cur_pos);
			}
		}
		vector<vector<int>> all_path;
		vector<int> one_path;
		dfs(dp, end, one_path, all_path, start);
		//cout << "Size" << "\t" << all_path.size() << endl;
		for (int i = 0; i < all_path.size(); ++i) {
			vector<int> one_path = all_path[i];
			vector<string> one_path_str(one_path.size(), "");
			for (int j = 0; j < one_path.size(); ++j) {
				one_path_str[j] = wordList[one_path[j]];
			}
			res.push_back(one_path_str);
		}
		return res;
	}
	
	void write(vector<vector<int>>& graph, vector<string>& wordList) {
		for (int i = 0; i < graph.size(); ++i) {
			cout << wordList[i] << ":";
			for (int j = 0; j < graph[i].size(); ++j) {
				cout << "\t" << wordList[graph[i][j]];
			}
			cout << endl;
		}
	}

	void dfs(vector<vector<int>> & dp, int cur_pos, vector<int>& one_path, vector<vector<int>>& all_path, int start) {
		if (cur_pos == start) {
			one_path.push_back(start);
			reverse(one_path.begin(), one_path.end());
			all_path.push_back(one_path);
			return;
		}
		vector<int> edges = dp[cur_pos];
		for (int i = 0; i < edges.size(); ++i) {
			vector<int> new_path = one_path;
			new_path.push_back(cur_pos);
			dfs(dp, edges[i], new_path, all_path, start);
		}
	}

	bool is_edge(string& w1, string& w2) {
		int notSame = 0;
		for (int i = 0; i < w1.length(); ++i) {
			if (w1[i] != w2[i]) {
				notSame += 1;
				if (notSame > 1) return false;
			}
		}
		return (notSame == 1);
	}
};
