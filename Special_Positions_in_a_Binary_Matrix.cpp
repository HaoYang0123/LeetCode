//Leetcode 1582
//时间复杂度为O(N^2)

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> row(n, 0);
        vector<int> col(m, 0);
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                row[i] += mat[i][j];
                col[j] += mat[i][j];
            }
        }
        int res = 0;
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                if(mat[i][j] == 1 && row[i] == 1 && col[j] == 1) ++res;
            }
        }
        return res;
    }
};
