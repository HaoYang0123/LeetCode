// Leetcode 802
//找图中是否有环，用拓扑排序

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> qs;
        vector<int> out(n, 0);
        vector<vector<int>> inv(n, vector<int>());
        unordered_set<int> safe_node;
        for(int i=0; i<n; ++i) {
            vector<int> & edges = graph[i];
            for(int j=0; j<edges.size(); ++j) {
                out[i]++;
                inv[edges[j]].push_back(i);
            }
            if(edges.size() == 0) qs.push(i);
        }
        while(!qs.empty()) {
            int c = qs.front();
            qs.pop();
            safe_node.insert(c);
            vector<int> & invedges = inv[c];
            for(int i=0; i<invedges.size(); ++i) {
                out[invedges[i]]--;
                if(out[invedges[i]] == 0) qs.push(invedges[i]);
            }
        }
        vector<int> res;
        for(auto idx=safe_node.begin(); idx!=safe_node.end(); ++idx) res.push_back(*idx);
        sort(res.begin(), res.end());
        return res;
    }
};
