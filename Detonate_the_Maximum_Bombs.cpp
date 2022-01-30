// Leetcode 2101

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n, vector<int>());
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(can_connect(bombs[i], bombs[j])) {
                    graph[i].push_back(j);
                }
            }
        }
        //cout<<"OK"<<endl;
        int res = 0;
        //BFS搜索
        for(int i=0; i<n; ++i) {  //枚举
            res = max(res, bfs(i, graph));
        }
        return res;
    }
    
    inline int bfs(int i, vector<vector<int>> & graph) {
        //如果选择第i个炸弹，返回总共有多少个炸弹爆炸
        int n = graph.size();
        vector<bool> is_vis(n, false);
        is_vis[i] = true;
        int res = 1;
        queue<int> qs;
        qs.push(i);
        while(!qs.empty()) {
            int idx = qs.front();
            qs.pop();
            vector<int> & edges = graph[idx];
            for(int j=0; j<edges.size(); ++j) {
                if(is_vis[edges[j]]) continue;
                is_vis[edges[j]] = true;
                ++res;
                qs.push(edges[j]);
            }
        }
        return res;
    }
    
    inline bool can_connect(vector<int> & a, vector<int> & b) {
        int x1 = a[0], y1 = a[1], r1 = a[2];
        int x2 = b[0], y2 = b[1], r2 = b[2];
        return get_dis(x1, y1, x2, y2) <= r1;
    }
    
    inline double get_dis(int x1, int y1, int x2, int y2) {
        double delta_x = abs(x2-x1);
        double delta_y = abs(y2-y1);
        return sqrt(delta_x*delta_x + delta_y*delta_y);
    }
};
