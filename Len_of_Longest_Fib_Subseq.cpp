//Leetcode 873
//动态规划：O(n^2)的时间复杂度和O(n^2)的空间复杂度

class Solution {
public:
    unordered_map<int, int> mm;
    int lenLongestFibSubseq(vector<int>& A) {
        mm.clear();
        int n=A.size();
        for(int i=0;i<n;++i) mm[A[i]] = i;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int res = 0;
        for(int i=0;i<n;++i) {
            for(int j=i+1;j<n;++j) {
                int tmp = find(A, i, j, dp);
                res = max(res, tmp);
            }
        }
        if(res <= 2) return 0;
        return res;
    }
    
    int find(vector<int> & A, int i, int j, vector<vector<int>> & dp) {
        if(dp[i][j] != 0) return dp[i][j];
        int a = A[i] + A[j];
        auto ind = mm.find(a);
        if(ind == mm.end()) {
            dp[i][j] = 2;
            return 2;
        }
        dp[i][j] = find(A, j, ind->second, dp) + 1;
        return dp[i][j];
    }
};
