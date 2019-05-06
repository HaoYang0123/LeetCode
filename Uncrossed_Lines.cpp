//Leetcode 1035
//动态规划

class Solution {
public:
    int n,m;
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        n = A.size();
        m = B.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        dfs(A,0,B,0,dp);
        return dp[0][0];
    }
    
    int dfs(vector<int> & A, int i, vector<int> & B, int j, vector<vector<int>> & dp) {
        if(i>=n||j>=m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int res = 0;
        for(int k=i;k<n;++k) {
            int p = j;
            while(p<m) {
                if(B[p]==A[k]) break;
                ++p;
            }
            if(p>=m) continue;
            int tmp = dfs(A,k+1,B,p+1,dp)+1;
            if(tmp>res) res=tmp;
        }
        dp[i][j] = res;
        return res;
    }
};
