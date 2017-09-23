#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> findRoot(vector<vector<int>> & graphs, vector<int> & inEv, int n) {
	vector<int> res;
	vector<bool> isVis(n+1);
	while(true) {
		vector<int> tmp;
		for(int i = 1; i <= n; ++i) {
			if(isVis[i])continue;
			if(inEv[i] == 0) {
				isVis[i] = true;
				tmp.push_back(i);
			}
		}
		res.insert(res.end(), tmp.begin(), tmp.end());
		if(res.size() >= n) break;
		for(int i = 0; i < tmp.size(); ++i) {
			int a = tmp[i];
			vector<int> edges = graphs[a];
			for(int j = 0; j < edges.size(); ++j) {
				--inEv[edges[j]];
			}
		}
	}
	return res;
}

int main() {
	ifstream fi("C:\\Users\\pFind\\Downloads\\3- sample_input.txt");
	ofstream fo("res.txt");
	int T;
	fi>>T;
	for(int t = 1; t <= T; ++t) {
		int n,e;
		fi>>n>>e;
		vector<vector<int>> graphs(n+1, vector<int>());
		vector<int> inEv(n+1, 0);
		for(int i = 0; i < e; ++i) {
			int a, b;
			fi>>a>>b;
			++inEv[b];
			graphs[a].push_back(b);
		}
		vector<int> res = findRoot(graphs, inEv, n);
		fo<<"#"<<t;
		for(int i = 0; i < res.size(); ++i) fo<<" "<<res[i];
		fo<<endl;
	}
	fo.close();
	fi.close();
	return 0;
}
