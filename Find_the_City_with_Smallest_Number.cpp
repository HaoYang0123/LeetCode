//Leetcode 1334
//使用优化队列实现Dijkstra算法

class Solution {
public:
    typedef pair<int,int> PIL;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> graph(n, vector<int>());
        vector<vector<int>> weight(n, vector<int>(n, 0));
        for(int i = 0; i < edges.size(); ++i) {
            vector<int> & e = edges[i];
            int v0 = e[0], v1 = e[1], wei = e[2];
            graph[v0].push_back(v1);
            graph[v1].push_back(v0);
            weight[v0][v1] = wei;
            weight[v1][v0] = wei;
        }
        int min_num = INT_MAX, res = -1;
        for(int i = 0; i < n; ++i) {
            int cur_num = get_city_num(n, graph, weight, distanceThreshold, i);
            //cout<<i<<"\t"<<cur_num<<endl;
            if(cur_num <= min_num) {
                min_num = cur_num;
                res = i;
            }
        }
        return res;
    }
    
    inline int get_city_num(int n, vector<vector<int>> & graph, vector<vector<int>> & weight, int dis, int start) {
        priority_queue<PIL, vector<PIL>, greater<PIL>> qs;
        qs.push(pair<int,int>(0, start));
        vector<int> is_vis(n, INT_MAX);
        is_vis[start] = 0;
        int res = 0;
        while(!qs.empty()) {
            PIL cur_tmp = qs.top();
            qs.pop();
            int cur = cur_tmp.second, cur_dis = cur_tmp.first;
            vector<int> & edges = graph[cur];
            for(int i = 0; i < edges.size(); ++i) {
                int e = edges[i];
                int new_dis = cur_dis + weight[cur][e];
                if(new_dis < is_vis[e]) {
                    qs.push(pair<int,int>(new_dis, e));
                    //cout<<"end\t"<<start<<"\t"<<e<<"\t"<<new_dis<<endl;
                    is_vis[e] = new_dis;
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            if(i != start && is_vis[i] <= dis) ++res;
        }
        return res;
    }
};
