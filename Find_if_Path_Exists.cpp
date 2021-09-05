// Leetcode 1971
//BFS

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        if(start == end) return true;
        vector<bool> is_vis(n, false);
        is_vis[start] = true;
        vector<vector<int>> graph(n, vector<int>());
        for(int i=0;i<edges.size();++i) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> qs;
        qs.push(start);
        while(!qs.empty()) {
            int cur = qs.front();
            qs.pop();
            vector<int> & e = graph[cur];
            for(int i=0; i<e.size(); ++i) {
                if(e[i] == end) return true;
                if(is_vis[e[i]]) continue;
                is_vis[e[i]] = true;
                qs.push(e[i]);
            }
        }
        return false;
    }
};
