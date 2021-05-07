// Leetcode 1572

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int res = 0;
        for(int i=0; i<n; ++i) res += (mat[i][i] + mat[i][n-1-i]);
        if(n % 2 == 0) return res;
        return res - mat[n/2][n/2];
    }
};
