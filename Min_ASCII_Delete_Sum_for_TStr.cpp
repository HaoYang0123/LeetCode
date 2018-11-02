//Leetcode 712
//动态规划

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int l1 = s1.length(), l2 = s2.length();
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,0)); //dp[i][j]表示为s1[i:]和s2[j:]的结果，最终结果为dp[0][0]
        dp[l1][l2-1] = int(s2[l2-1]);
        dp[l1-1][l2] = int(s1[l1-1]);
        for(int i=l2-2;i>=0;--i) dp[l1][i]=dp[l1][i+1]+int(s2[i]);
        for(int i=l1-2;i>=0;--i) dp[i][l2]=dp[i+1][l2]+int(s1[i]);
        for(int i=l1-1;i>=0;--i) {
            for(int j=l2-1;j>=0;--j) {
                if(s1[i]==s2[j]) {
                    dp[i][j]=dp[i+1][j+1];
                }
                else {
                    dp[i][j]=min(dp[i+1][j]+int(s1[i]),dp[i][j+1]+int(s2[j]));
                }
                //cout<<i<<"\t"<<j<<"\t"<<dp[i][j]<<endl;
            }
        }
        return dp[0][0];
    }
};
