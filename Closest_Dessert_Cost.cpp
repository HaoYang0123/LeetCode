// Leetcode 1774

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int res = 0, abs_r = INT_MAX;
        vector<int> top_list;
        dfs(toppingCosts, 0, 0, top_list);
        for(int i=0;i<baseCosts.size();++i) {
            for(int j=0;j<top_list.size();++j) {
                int c = baseCosts[i] + top_list[j];
                res = get_vs(c, target, res, abs_r);
                abs_r = abs(res - target);
            }
        }
        return res;
    }
    
    void dfs(vector<int> & top, int cur_c, int idx, vector<int> & top_list) {
        if(idx >= top.size())  {
            top_list.push_back(cur_c);
            return ;
        }
        dfs(top, cur_c, idx+1, top_list); //0个idx的toppingCosts
        cur_c += top[idx];   // 1个idx的toppingCosts
        dfs(top, cur_c, idx+1, top_list);
        cur_c += top[idx];   //2个idx的toppingCosts
        dfs(top, cur_c, idx+1, top_list);
    }
    
    
    inline int get_vs(int c, int target, int ori_c, int abs_r) {
        if(abs(c - target) < abs_r) return c;
        if(abs(c - target) <= abs_r) return min(c, ori_c);
        return ori_c;
    }
};
