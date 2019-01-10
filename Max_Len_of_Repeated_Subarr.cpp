//Leetcode 718
//O(n^2)时间复杂度，动态规划

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n=A.size(), m=B.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        int res = 0;
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                if(A[i]==B[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                    if(dp[i+1][j+1] > res) res = dp[i+1][j+1];
                }
            }
        }
        return res;
    }
};
