//Leetcode 851
//动态规划

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int> dp(n,-1);
        vector<vector<int>> map(n,vector<int>());
        for(int i=0;i<richer.size();++i) {
            map[richer[i][1]].push_back(richer[i][0]);
        }
        vector<int> res(n,0);
        for(int i=0;i<n;++i) {
            int min = get_res(dp, i, map, quiet);
            res[i] = min;
        }
        return res;
    }
    
    int get_res(vector<int> & dp, int index, vector<vector<int>> & map, vector<int> & quiet) {
        if(dp[index] != -1) return dp[index];
        vector<int> edge = map[index];
        if(edge.size() == 0) return index;
        int min_quiet = quiet[index], min_index = index;
        for(int i=0;i<edge.size();++i) {
            int min = get_res(dp, edge[i], map, quiet);
            int min_value = quiet[min];
            if(min_quiet > min_value) {
                min_quiet = min_value;
                min_index = min;
            }
        }
        dp[index] = min_index;
        return min_index;
    }
};
