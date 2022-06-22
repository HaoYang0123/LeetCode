// Leetcode 2310

class Solution {
public:
    int res;
    int distributeCookies(vector<int>& cookies, int k) {
        res = INT_MAX;
        vector<int> child(k, 0);
        dfs(0, cookies, child);
        return res;
    }
    
    void dfs(int i, vector<int> & cookies, vector<int> & child) {
        if(i == cookies.size()) {
            int max_v = 0;
            for(int j=0; j<child.size(); ++j) max_v = max(max_v, child[j]);
            res = min(res, max_v);
            return ;
        }
        for(int j=0; j<child.size(); ++j) {
            child[j] += cookies[i];
            dfs(i+1, cookies, child);
            child[j] -= cookies[i];
        }
    }
};
