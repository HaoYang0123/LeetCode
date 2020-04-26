//Leetcode 1416
//动态规划，时间复杂度O(N logk)， N为字符串s的长度，logk表示k的10进制位数，因为每次要枚举所有<=k的情况

class Solution {
public:
    int MOD;
    int numberOfArrays(string s, int k) {
        MOD = 1000000007;
        int n = s.length();
        vector<long long> dp(n, -1); //dp[i]记录s[i...]的结果数量
        return dfs(s, 0, k, dp);
    }
    
    long long dfs(string & s, int i, int k, vector<long long> & dp) {
        if(i >= s.length()) return 1;
        if(dp[i] != -1) return dp[i];
        if(s[i] == '0') return 0; //不能有leading zeros
        long long curv = 0; //必须使用long long，用int会超出范围
        long long res = 0; //同上
        for(int j=i;j<s.length();++j) {
            curv = curv * 10 + int(s[j]-'0');
            if(curv > k) break; //枚举所有<=k的情况
            res = (res + dfs(s, j+1, k, dp)) % MOD;
        }
        dp[i] = res;
        return res;
    }
};
