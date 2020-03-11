//Leetcode 1376
//先根据manager，生成树结构信息，记录结点的儿子结点信息（代码中的trees变量）
//动态规划，记录结点发布信息（即以该结点作为根结点，传输信息至所有叶子）花费时间

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> trees(n, vector<int>()); //trees[i]表示i包含的员工
        for(int i=0;i<n;++i) {
            if(manager[i]==-1) continue;
            trees[manager[i]].push_back(i);
        }
        vector<int> dp(n, -1);
        return dfs(trees, dp, headID, informTime);
    }
    
    int dfs(vector<vector<int>> & trees, vector<int> & dp, int root, vector<int> & informTime) {
        if(dp[root] != -1) return dp[root];
        vector<int> & children = trees[root];
        int res = 0;
        for(int i=0;i<children.size();++i) {
            res = max(res, dfs(trees, dp, children[i], informTime));
        }
        dp[root] = res + informTime[root];
        return dp[root];
    }
};
