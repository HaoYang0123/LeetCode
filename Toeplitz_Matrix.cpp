//Leetcode 766

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        for(int i=n-2;i>=0;--i) { //倒数第二行的第一列开始（左下角因为只有一个元素，无需判断）
            int v=matrix[i][0];
            for(int j=1;i+j<n;++j) {
                if(j>=m) break;
                if(matrix[i+j][j]!=v) return false;
            }
        }
        for(int j=1;j<m-1;++j) { //到达第一行后，从第一行的第二列开始继续（最后的右上角也因为只有一个元素，无需判断）
            int v=matrix[0][j];
            for(int i=1;i+j<m;++i) {
                if(i>=n) break;
                if(matrix[i][i+j]!=v) return false;
            }
        }
        return true;
    }
};
