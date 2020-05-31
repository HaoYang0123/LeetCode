//Leetcode 1466
//宽度搜索

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n, vector<int>()), flag(n, vector<int>());
        // graph记录各节点连接情况，flag记录是正向连接还是反向连接
        vector<bool> is_vis(n, false); //记录结点是否已经访问
        for(int i=0;i<connections.size();++i) {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
            flag[connections[i][0]].push_back(1); //需要反转
            flag[connections[i][1]].push_back(-1); //不需要反转
        }
        is_vis[0] = true;
        queue<int> qs;
        qs.push(0);
        int res = 0;
        while(!qs.empty()) {
            int cur = qs.front();
            qs.pop();
            vector<int> & can_go = graph[cur];
            vector<int> & cur_flag =flag[cur];
            for(int i=0;i<can_go.size();++i) {
                if(is_vis[can_go[i]]) continue; //如果结点已经访问，则不需要再访问
                is_vis[can_go[i]] = true;
                if(cur_flag[i] == 1) ++res;
                qs.push(can_go[i]);
            }
        }
        return res;
    }
};
