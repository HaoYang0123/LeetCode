#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void dfs(vector<vector<int>> & graphs, int n, int index, vector<bool> isVis, int curRes, int & res) {
	bool noE = true;
	for(int i = 1; i <= n; ++i) {
		if(isVis[i]) continue;
		isVis[i] = true;
		noE = false;
		dfs(graphs, n, i, isVis, curRes + graphs[index][i], res);
		isVis[i] = false;
	}
	if(noE) {
		int tmp = curRes + graphs[index][n + 1];
		if(tmp < res) res = tmp;
	}
}

int main() {
	ifstream fi("2- sample_input.txt");
	ofstream fo("res.txt");
	int T;
	fi>>T;
	for(int t = 1; t <= T; ++t) {
		int n;
		fi>>n;
		vector<pair<int, int>> points(n + 2);
		int x,y;
		fi>>x>>y;
		points[0] = pair<int, int>(x, y);
		fi>>x>>y;
		points[n + 1] = pair<int, int>(x, y);
		for(int i = 1; i <= n; ++i) {
			fi>>x>>y;
			points[i] = pair<int,int>(x,y);
		}
		vector<bool> isVis(n + 2);
		vector<vector<int>> graphs(n + 2, vector<int>(n + 2, 0));
		for(int i = 0; i < n + 2; ++i) {
			for(int j = i + 1; j < n + 2; ++j) {
				int e = abs(points[i].first - points[j].first) + abs(points[i].second - points[j].second);
				graphs[i][j] = graphs[j][i] = e;
			}
		}
		int res = INT_MAX;
		dfs(graphs, n, 0, isVis, 0, res);
		fo<<"#"<<t<<" "<<res<<endl;
	}
	fo.close();
	fi.close();
	return 0;
}
