//计算字符串的所有切割形式，使得切割得到的子串是回文串
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> curRes;
        vector<vector<string>> res;
        dfs(s, 0, curRes, res);
        return res;
    }
    
    void dfs(string & s, int pos, vector<string> & curRes, vector<vector<string>> & res) {
        if(pos == s.length()) res.push_back(curRes);
        for(int i = pos; i < s.length(); ++i) {
            if(!isPal(s, pos, i)) continue;
            vector<string> newRes = curRes;
            newRes.push_back(s.substr(pos, i - pos + 1));
            dfs(s, i + 1, newRes, res);
        }
    }
    
    bool isPal(string & s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
};

//计算字符串的最小切割，让每个切割得到的子串是回文串。Hard
class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> pal(n, vector<bool>(n, false)); //pal[i][j]表示字符串[i, j]是否为回文
        vector<int> dp(n); //dp[i]表示字符串[i, n - 1]的最小切割，那么dp[0]则为答案
        for(int i = n - 1; i >= 0; --i) {
            dp[i] = n - i - 1;
            for(int j = i; j < n; ++j) {
                if(s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                    if(j == n - 1) dp[i] = 0;
                    else dp[i] = min(dp[i], dp[j + 1] + 1);
                }
            }
        }
        return dp[0];
    }
};
