//Leetcode 1273
//深度搜索

class Solution {
public:
	int deleteTreeNodes(int nodes, vector<int> & parent, vector<int> & value) {
		vector<vector<int>> child(nodes);
		for(int i=1;i<nodes;++i) {
			child[parent[i]].push_back(i);
		}
		return dfs(child, value, 0).first;
	}

	pair<int,int> dfs(vector<vector<int>> & child, vector<int> & value, int index) {
		//pair<int,int> res; //res[0]表示求和为非0的数量，res[1]表示求和值
		vector<int> & edges = child[index];
		if(edges.size() == 0) { //叶子结点
			if(value[index] == 0) return pair<int,int>(0,0);
			return pair<int,int>(1,value[index]);
		}
		int cur_sum = value[index], cur_num = 1;
		for(int i=0;i<edges.size();++i) {
			pair<int,int> tmp = dfs(child, value, edges[i]);
			cur_num += tmp.first;
			cur_sum += tmp.second;
		}
		if(cur_sum == 0) return pair<int,int>(0,0);
		return pair<int,int>(cur_num, cur_sum);
	}
};
