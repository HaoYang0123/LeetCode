//Leetcode 1519
//自己写的WA，因为我没有对edges进行处理，有些例子，需要根据edges转化成树（知道哪个结点才是根结点）

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> dp(n, vector<int>(26,0)); //dp[i]记录第i个结点包含各字符的数量
        vector<bool> is_vis(n, false);
        vector<int> res(n, 0);
        vector<vector<int>> graph(n, vector<int>());
        for(int i=0;i<edges.size();++i) {
            graph[edges[i][0]].push_back(edges[i][1]); //【注：这里有些问题】
        }
        for(int i=0;i<n;++i) {
            res[i] = dfs(i, graph, labels, dp, is_vis);
        }
        return res;
    }
    inline int dfs(int root, vector<vector<int>> & graph, string & labels, vector<vector<int>> & dp, vector<bool> & is_vis) {
        int cur_c = int(labels[root]-'a');
        if(is_vis[root]) return dp[root][cur_c];
        vector<int> edges = graph[root];
        for(int c = 0; c < 26; ++c) {
            int res = 0;
            if(c == cur_c) res = 1;
            for(int i=0; i<edges.size(); ++i) {
                dfs(edges[i], graph, labels, dp, is_vis);
                res += dp[edges[i]][c];
            }
            dp[root][c] = res;
        }
        is_vis[root] = true;
        return dp[root][cur_c];
    }
};
