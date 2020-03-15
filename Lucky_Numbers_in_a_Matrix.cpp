//Leetcode 1380

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> res;
        for(int i=0;i<n;++i) {
            int minIndex = find_min_row(matrix[i]);
            int maxIndex = find_max_column(matrix, minIndex);
            if(maxIndex == i) res.push_back(matrix[i][minIndex]);
        }
        return res;
    }
    
    inline int find_min_row(vector<int> & row) {
        int index = -1;
        int minv = INT_MAX;
        for(int i=0;i<row.size();++i) {
            if(row[i] < minv) {
                index = i;
                minv = row[i];
            }
        }
        return index;
    }
    
    inline int find_max_column(vector<vector<int>> & mat, int j) {
        int index = -1;
        int maxv = INT_MIN;
        for(int i=0;i<mat.size();++i) {
            if(mat[i][j] > maxv) {
                index = i;
                maxv = mat[i][j];
            }
        }
        return index;
    }
};
