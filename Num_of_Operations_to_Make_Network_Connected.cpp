//Leetcode 1319

//方法1：使用宽度搜索，计算子图的数量
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int c_n = connections.size();
        if(c_n < n-1) return -1;
        int cur = 0;
        queue<int> qs;
        vector<bool> is_vis(n, false);
        set<int> not_vis; //记录哪些结点没有被考虑
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
                int nt = *not_vis.begin(); //快速找到第1个还没有考虑的结点（如果没有not_vis，只能枚举所有的is_vis，会超时）
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

//方法2：使用数组parent[i]来保存i的父亲的位置
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        vector<int> parent(n,-1);
        for(int i=0;i<connections.size();++i) {
            int p1 = find_parent(parent, connections[i][0]);
            int p2 = find_parent(parent, connections[i][1]);
            if(p1 != p2) parent[p2] = p1;
        }
        int subgraph_num = 0;
        for(int i=0;i<n;++i) {
            if(parent[i] == -1) ++subgraph_num;
        }
        return subgraph_num - 1;
    }
    
    inline int find_parent(vector<int> & parent, int ind) {
        while(parent[ind] >= 0) ind = parent[ind];
        return ind;
    }
};
