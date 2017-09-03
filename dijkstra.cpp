#include <iostream>
#include <vector>
#include <climits>
using namespace std;


void dijkstra(vector<vector<int>> & edge, vector<int> & dist, int s) {
	int n = edge.size();
	vector<bool> visited(n, false);
	dist[s] = 0;
	while(true) {
		int tmp = -1;
		int d = INT_MAX;
		for(int i = 0; i < n; ++i) {
			if(visited[i]) continue;
			if(dist[i] < d) {
				tmp = i;
				d = dist[i];
			}
		}
		if(tmp == -1) break;
		visited[tmp] = true;
		for(int i = 0; i < n; ++i) {
			if(visited[i]) continue;
			if(edge[tmp][i] == -1) continue;
			dist[i] = min(dist[i], dist[tmp] + edge[tmp][i]);
		}
	}
}

int main() {
	int T;
	cin>>T;
	for(int t = 1; t <= T; ++t) {
		int n,m,a,b;
		cin>>n>>m>>a>>b;
		vector<int> s(a), e(b);
		vector<vector<int>> edge(n, vector<int>(n));
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j) edge[i][j] = -1;
		for(int i = 0; i < a; ++i) cin>>s[i];
		for(int i = 0; i < b; ++i) cin>>e[i];
		for(int i = 0; i < m; ++i) {
			int t1, t2, w;
			cin>>t1>>t2>>w;
			--t1;
			--t2;
			edge[t1][t2] = edge[t2][t1] = w;
		}
		int res = INT_MAX;
		for(int i = 0; i < a; ++i) {
			vector<int> dist(n, INT_MAX);
			dijkstra(edge, dist, s[i] - 1);
			int tmpMin = INT_MAX;
			for(int j = 0; j < b; ++j) {
				tmpMin = min(tmpMin, dist[e[j] - 1]);
			}
			res = min(res, tmpMin);
		}
		if(res != INT_MAX) cout<<"Case #"<<t<<": "<<res<<endl;
		else cout<<"Case #"<<t<<": No answer"<<endl;
	}
	return 0;
}
