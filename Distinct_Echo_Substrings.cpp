//Leetcode 1316
//动态规划，O(N^2)，dp[i][j]表示text[i...(j-1)]与text[j...]，开头相同的字符串数量
//那么有动态转移：dp[i][j]=1+dp[i+1][j+1]，如果text[i]==text[j]
//然后，是最后备份，可以只备份前一半的字符串（因为后一半字符串与之相等），减少空间开销

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n=text.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        unordered_set<string> res;
        for(int j=n-1;j>=0;--j) {
            for(int i=j-1;i>=0;--i) {
                dp[i][j] = (text[i]==text[j] ? 1+dp[i+1][j+1] : 0);
                if(dp[i][j] >= j-i) res.insert(text.substr(i,j-i)); //只有dp[i][j]即分别从i和j开头的字符串相同数量比(j-i)的长度长，则说明满足要求
            }
        }
        return res.size();
    }
};
