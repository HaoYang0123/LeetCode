//Leetcode 797
//递归方法

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        return dfs(graph, 0);
    }
    
    vector<vector<int>> dfs(vector<vector<int>> & graph, int node) { //计算从node到达n-1结点的所有路径
        int n=graph.size();
        vector<vector<int>> res;
        if(node==n-1) {
            vector<int> path;
            path.push_back(n-1);
            res.push_back(path);
            return res;
        }
        
        vector<int> edges=graph[node];
        for(int i=0;i<edges.size();++i) {
            vector<vector<int>> paths = dfs(graph, edges[i]);
            for(int j=0;j<paths.size();++j) {
                paths[j].insert(paths[j].begin(), node);
                res.push_back(paths[j]);
            }
        }
        return res;
    }
};
