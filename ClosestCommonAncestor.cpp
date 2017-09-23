#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Res {
	bool left; //是否包含节点s
	bool right; //是否包含节点e
	int count; //当前节点为根的子树的节点数目

	Res(bool l, bool r, int c) : left(l), right(r), count(c) {}
};

bool isOK;
int res_index, res_count;

Res dfs(vector<vector<int>> & graph, int index, int s, int e) {
	if(isOK) return Res(false, false, 1);
	vector<int> edges = graph[index];
	if(edges.size() == 0) { //没孩子，是叶子结点
		Res r(false, false, 1);
		if(index == s) r.left = true;
		if(index == e) r.right = true;
		return r;
	}
	else if(edges.size() == 1) { //只有一个孩子
		Res child = dfs(graph, edges[0], s, e);
		Res r(child.left, child.right, child.count + 1);
		if(index == s) r.left = true;
		if(index == e) r.right = true;
		return r;
	}
	else  { //有两个孩子
		Res left = dfs(graph, edges[0], s, e), right = dfs(graph, edges[1], s, e);
		Res r(left.left || right.left, left.right || right.right, left.count + right.count + 1);
		if(index == s) r.left = true;
		if(index == e) r.right = true;
		if(!isOK && r.left && r.right) {
			isOK = true;
			res_index = index;
			res_count = r.count;
		}
		return r;
	}
}

int main() {
	ifstream fi("1- sample_input.txt");
	ofstream fo("res.txt");
	int T;
	fi>>T;
	for(int t = 1; t <= T; ++t) {
		int n,m,s,e;
		fi>>n>>m>>s>>e;
		vector<vector<int>> graph(n+1);
		vector<int> inEv(n+1, 0); //每个点的入度，判断根节点，根节点的入度为0
		for(int i = 0; i < m; ++i) {
			int a, b;
			fi>>a>>b;
			graph[a].push_back(b);
			++inEv[b];
		}
		int r = 0; //r表示根节点
		for(int i = 1; i <= n; ++i) {
			if(inEv[i] == 0) {
				r = i;
				break;
			}
		}
		isOK = false;
		dfs(graph, r, s, e);
		fo<<"#"<<t<<" "<<res_index<<" "<<res_count<<endl;
	}
	fo.close();
	fi.close();
	return 0;
}
