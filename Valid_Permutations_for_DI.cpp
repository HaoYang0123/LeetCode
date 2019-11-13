//Leetcode 903
//动态规划，时间复杂度为O(N^3)

class Solution {
public:
	int numPermsDISequence(string S) {
        int mod=1000000007;
        vector<vector<int>> dp(S.size()+1, vector<int>(S.size()+1, 0));
        dp[0][0]=1;
        for(int i=1;i<dp.size();i++) {
            for(int j=0;j<=i;j++) {
                if(S[i-1]=='D') {
                    for(int k=j;k<i;k++) dp[i][j]=(dp[i][j]+dp[i-1][k]%mod)%mod;
                }
                else {
                    for(int k=0;k<j;k++) dp[i][j]=(dp[i][j]+dp[i-1][k]%mod)%mod;
                }
            }
        }
        int res=0;
        for(int i=0;i<dp.size();i++) res=(res+dp.back()[i]%mod)%mod;
        return res;
    }
};
