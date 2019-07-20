//Leetcode 51
//N皇后问题，深度搜索，每次判断当前行可以放Queeue的列位置（当前的列位置不能与之前放的同列，或者正、反对角线）

class Solution {
public:
    string oneline;
    vector<vector<string>> solveNQueens(int n) {
        oneline = "";
        for(int i=0;i<n;++i) oneline += ".";
        vector<vector<string>> res;
        vector<int> cur_res;
        dfs(res, cur_res, n);
        return res;
    }
    
    void dfs(vector<vector<string>> & res, vector<int> & cur_res, int n) {
        if(cur_res.size() == n) {
            vector<string> rr(n,oneline);
            for(int i=0;i<n;++i) {
                rr[i][cur_res[i]] = 'Q';
            }
            res.push_back(rr);
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
