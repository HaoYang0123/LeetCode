//Leetcode 1314
//时间复杂度为O(N^3)

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i=0;i<m;++i) dp[0][i] = mat[0][i];
        for(int i=1;i<n;++i) {
            for(int j=0;j<m;++j) dp[i][j] = dp[i-1][j] + mat[i][j];
        }
        vector<vector<int>> res(n, vector<int>(m, 0));
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                int start_r = max(0, i - K);
                int end_r = min(i + K, n - 1);
                int start_c = max(0, j - K);
                int end_c = min(j + K, m - 1);
                int tmp = 0;
                if(start_r == 0) {
                    for(int k=start_c;k<=end_c;++k) tmp += dp[end_r][k];
                }
                else {
                    for(int k=start_c;k<=end_c;++k) tmp += (dp[end_r][k] - dp[start_r-1][k]);
                }
                res[i][j] = tmp;
            }
        }
        return res;
    }
};
