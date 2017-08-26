class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.length() == 0 || s.length() == 0) return 0;
        int n = t.length(), m = s.length();
        vector<vector<int>> dp(n, vector<int>(m));
        dp[0][0] = (s[0] == t[0] ? 1 : 0);
        for(int i = 1; i < m; ++i) {
            if(s[i] != t[0]) dp[0][i] = dp[0][i - 1];
            else dp[0][i] = dp[0][i - 1] + 1;
        }
        for(int j = 1; j < n; ++j) {
            for(int i = j; i < m; ++i) {
                if(s[i] != t[j]) dp[j][i] = dp[j][i - 1];
                else dp[j][i] = dp[j][i - 1] + dp[j - 1][i - 1];
            }
        }
        return dp[n - 1][m - 1];
    }
};
