//Leetcode 931
//动态规划： dp[i][j]=A[i][j]+min(dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1])

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<m;++i) dp[0][i] = A[0][i];
        for(int i=1;i<n;++i) {
            for(int j=0;j<m;++j) {
                int minv = dp[i-1][j];
                if(j-1>=0 && dp[i-1][j-1]<minv) minv = dp[i-1][j-1];
                if(j+1<m && dp[i-1][j+1]<minv) minv = dp[i-1][j+1];
                dp[i][j] = minv + A[i][j];
            }
        }
        int res=dp[n-1][0];
        for(int i=1;i<m;++i) {
            if(dp[n-1][i]<res) res = dp[n-1][i];
        }
        return res;
    }
};
