// Leetcode 2039
//BFS广度搜索

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        // BFS广度搜索
        int n = patience.size();
        vector<vector<int>> es(n, vector<int>());
        for(int i=0; i<edges.size(); ++i) {
            es[edges[i][0]].push_back(edges[i][1]);
            es[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> is_vis(n, -1);  //is_vis[i]表示从起点（0）至i的最短距离，使用BFS搜索
        is_vis[0] = 0;
        queue<pair<int,int>> qs;
        qs.push({0,0});
        while(!qs.empty()) {
            pair<int,int> cur = qs.front();  //当前结点
            qs.pop();
            vector<int> & can_go = es[cur.first];  //当前结点所连接的边
            for(int i=0; i<can_go.size(); ++i) {
                if(is_vis[can_go[i]] != -1) continue;  //已经到达了
                is_vis[can_go[i]] = cur.second+1;
                qs.push({can_go[i], cur.second+1});
            }
        }
        int res = 0;
        for(int i=1; i<n; ++i) {
            int vv = is_vis[i] * 2;  //第1个消息到达自己的时间
            int inv = patience[i];  //0, inv, 2*inv, 3*inv, ...发送消息
            //所以，需要找到最大的一个比vv小的值，比如: vv=4, inv=1, 那么就是3（表示会发送：A, B, C，三条消息）。不会发送第四条消息，因为第1条消息已经返回
            int ys = vv / inv;
            int fs = ys * inv; 
            if(vv % inv == 0) fs -= inv;  //fs是发送最后一条C消息的发送时间
            res = max(res, fs + vv);  //fs+vv，表示接受回来C消息的接收时间
        }
        return res+1;
    }
};
