//Leetcode 1284
//动态规划，并且矩阵中任意一点不会反转两次（最多一次），因为反转两次后就相当于回到之前状态了

class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        unordered_map<int, int> dp;
        vector<vector<bool>> is_vis(mat.size(), vector<bool>(mat[0].size(), false));
        dp[0] = 0;
        int res = dfs(mat, dp, is_vis);
        if(res == INT_MAX) res = -1;
        return res;
    }
    
    int dfs(vector<vector<int>> & mat, unordered_map<int, int> & dp, vector<vector<bool>> & is_vis) {
        int key = get_key(mat);
        auto ind = dp.find(key);
        if(ind != dp.end()) return ind->second;
        int min_step = INT_MAX;
        for(int i=0;i<mat.size();++i) {
            for(int j=0;j<mat[0].size();++j) {
                if(is_vis[i][j]) continue;
                is_vis[i][j] = true;
                update_state(mat, i, j);
                int new_key = get_key(mat);
                int tmp = dfs(mat, dp, is_vis);
                min_step = min(min_step, tmp);
                update_state(mat, i, j);
                is_vis[i][j] = false;
            }
        }
        if(min_step != INT_MAX) min_step++;
        dp[key] = min_step;
        return min_step;
    }
    
    inline void update_state(vector<vector<int>> & state, int i, int j) {
        int r_step[] = {0,0,-1,1};
        int c_step[] = {-1,1,0,0};
        state[i][j] = (state[i][j] ? 0 : 1);
        for(int k=0;k<4;++k) {
            int new_i = i+r_step[k];
            int new_j = j+c_step[k];
            if(new_i < 0 || new_i >= state.size()) continue;
            if(new_j < 0 || new_j >= state[0].size()) continue;
            state[new_i][new_j] = (state[new_i][new_j] ? 0 : 1);
        }
    }
    
    inline int get_key(vector<vector<int>> & state) {
        int key = 0, mul = 1;
        for(int i = 0; i < state.size(); ++i) {
            for(int j = 0; j < state[0].size(); ++j) {
                key += mul * state[i][j];
                mul *= 2;
            }
        }
        return key;
    }
};
