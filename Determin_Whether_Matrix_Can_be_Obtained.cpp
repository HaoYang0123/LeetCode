// Leetcode 1886

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(is_equal(mat, target)) return true;
        rotate_90(mat);
        if(is_equal(mat, target)) return true;
        rotate_90(mat);
        if(is_equal(mat, target)) return true;
        rotate_90(mat);
        if(is_equal(mat, target)) return true;
        return false;
    }
    
    inline bool is_equal(vector<vector<int>> & mat, vector<vector<int>> & target) {
        int n = mat.size(), m = mat[0].size();
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(mat[i][j] != target[i][j]) return false;
            }
        }
        return true;
    }
    
    inline void rotate_90(vector<vector<int>> & mat) {
        //矩阵(n*m, n不一定等于m)，顺时针旋转90度
        int n = mat.size(), m = mat[0].size(); //n==m
        int row = n/2-1;
        int col = (m-1)/2;
        for(int i=0; i<=row; ++i) {
            for(int j=0; j<=col; ++j) {
                swap(mat[i][j], mat[j][m-1-i]);
                swap(mat[i][j], mat[n-1-i][m-1-j]);
                swap(mat[i][j], mat[n-1-j][i]);
            }
        }
    }
};
