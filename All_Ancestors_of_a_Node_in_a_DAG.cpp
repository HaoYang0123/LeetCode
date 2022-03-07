// Leetcode 2192
//拓扑排序

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>> res(n, set<int>());
        vector<int> in_deg(n, 0);
        vector<vector<int>> graph(n, vector<int>());
        for(int i=0; i<edges.size(); ++i) {
            int x = edges[i][0], y = edges[i][1];
            in_deg[y]++;
            graph[x].push_back(y);
        }
        queue<int> qs;
        //拓扑排序，先找到入度为0的结点，这些结点是没有“祖先”的
        for(int i=0; i<n; ++i) {
            if(in_deg[i] == 0) qs.push(i);
        }
        while(!qs.empty()) {  //由于没有环，所以一定有入度为0的结点
            int cur = qs.front();
            set<int> & cur_prev = res[cur];
            qs.pop();
            vector<int> & next_nodes = graph[cur];
            for(int i=0; i<next_nodes.size(); ++i) {
                int next_n = next_nodes[i];
                res[next_n].insert(cur);
                for(auto idx=cur_prev.begin(); idx!=cur_prev.end(); ++idx) res[next_n].insert(*idx);
                --in_deg[next_n];
                if(in_deg[next_n] == 0) qs.push(next_n);
            }
        }
        vector<vector<int>> res2(n, vector<int>());
        for(int i=0; i<n; ++i) {
            vector<int> tmp;
            for(auto idx=res[i].begin(); idx!=res[i].end(); ++idx)
                res2[i].push_back(*idx);
        }
        return res2;
    }
};
