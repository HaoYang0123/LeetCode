//Leetcode 1319

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int c_n = connections.size();
        if(c_n < n-1) return -1;
        int cur = 0;
        queue<int> qs;
        vector<bool> is_vis(n, false);
        set<int> not_vis;
        for(int i=1;i<n;++i) not_vis.insert(i);
        vector<vector<int>> graph(n,vector<int>());
        for(int i=0;i<c_n;++i) {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        qs.push(0);
        //int start = 0;
        is_vis[0] = true;
        ++cur;
        int subgraph_num = 1; //子图的数量
        while(cur < n) {
            int t = qs.front();
            qs.pop();
            vector<int> & edges = graph[t];
            for(int i=0;i<edges.size();++i) {
                int nt = edges[i];
                if(is_vis[nt]) continue;
                is_vis[nt] = true;
                not_vis.erase(nt);
                ++cur;
                qs.push(nt);
            }
            if(cur >= n) break;
            if(qs.empty()) { //说明当前子图的已经处理过了
                //cout<<"In\t"<<start<<"\t"<<cur<<endl;
                int nt = *not_vis.begin();
                not_vis.erase(nt);
                is_vis[nt] = true;
                ++cur;
                ++subgraph_num;
                qs.push(nt);
            }
        }
        //cout<<start<<"\t"<<cur<<endl;
        return subgraph_num - 1;
    }
};
