//Leetcode 91
//动态规划，时间复杂度O(N)，需要考虑开头为0的特殊情况

class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n,-1);
        return dfs(s, 0, dp);
    }
    
    int dfs(string & s, int start, vector<int> & dp) {
        if(start==s.length()) return 1;
        if(s[start]=='0') return 0;
        if(s.length()-1==start) return 1;
        if(dp[start] != -1) return dp[start];
        if(s[start]=='1' || (s[start]=='2' && s[start+1]<='6')) {
            int v = dfs(s, start+1, dp) + dfs(s, start+2, dp);
            dp[start]=v;
            return v;
        }
        else {
            int v = dfs(s, start+1, dp);
            dp[start]=v;
            return v;
        }
    }
};
