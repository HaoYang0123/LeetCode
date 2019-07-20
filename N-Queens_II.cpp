//Leetcode 52
//N皇后问题，与leetcode 51是同样的解法

class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int> cur_res;
        dfs(res, cur_res, n);
        return res;
    }
    
    void dfs(int & res, vector<int> & cur_res, int n) {
        if(cur_res.size() == n) {
            res++;
            return;
        }
        
        for(int i=0;i<n;++i) {
            bool is_ok = true;
            for(int j=0;j<cur_res.size();++j) {
                if(cur_res[j]==i || abs(cur_res[j]-i) == cur_res.size()-j) {
                    is_ok = false;
                    break;
                }
            }
            if(is_ok) {
                vector<int> new_res = cur_res;
                new_res.push_back(i);
                dfs(res, new_res, n);
            }
        }
    }
};
