//Leetcode 784

class Solution {
public:
    vector<string> res;
    vector<string> letterCasePermutation(string S) {
        string curStr = "";
        dfs(S, 0, curStr);
        return res;
    }
    
    void dfs(string & S, int a, string & curStr) {
        if(a==S.length()) {
            res.push_back(curStr);
            return;
        }
        if(S[a] >= 'a' && S[a] <= 'z') {
            string newStr = curStr + S[a];
            dfs(S, a+1, newStr);
            newStr = curStr + (char)('A' + (int)(S[a]-'a'));
            dfs(S, a+1, newStr);
        }
        else if(S[a] >= 'A' && S[a] <= 'Z') {
            string newStr = curStr + S[a];
            dfs(S, a+1, newStr);
            newStr = curStr + (char)('a' + (int)(S[a]-'A'));
            dfs(S, a+1, newStr);
        }
        else {
            string newStr = curStr + S[a];
            dfs(S, a+1, newStr);
        }
    }
};
