//Leetcode 1519

class Solution {
public:
    vector<int> final_res;
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> dp(n, vector<int>(26,0)); //dp[i]记录第i个结点包含各字符的数量
        vector<bool> is_vis(n, false);
        final_res.resize(n);
        vector<vector<int>> graph(n, vector<int>());
        for(int i=0;i<edges.size();++i) {
            graph[edges[i][0]].push_back(edges[i][1]); //注：这里是无向图
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0, graph, labels, dp, is_vis); //根据题意，结点0为根结点，从根结点使用深度搜索，计算dp
        return final_res;
    }
    inline void dfs(int root, vector<vector<int>> & graph, string & labels, vector<vector<int>> & dp, vector<bool> & is_vis) {
        int cur_c = int(labels[root]-'a');
        if(is_vis[root]) return ;
        is_vis[root] = true;
        vector<int> & edges = graph[root];
        dp[root][cur_c] = 1;
        for(int i=0; i<edges.size(); ++i) { //枚举所有的子树
            if(is_vis[edges[i]]) continue; //如果计算过，则不考虑
            dfs(edges[i], graph, labels, dp, is_vis);
            for(int c = 0; c < 26; ++c) { //更新所有的字符情况
                dp[root][c] += dp[edges[i]][c];
            }
        }
        final_res[root] = dp[root][cur_c];
    }
};
