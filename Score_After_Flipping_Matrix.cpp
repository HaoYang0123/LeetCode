//Leetcode 861
//给定一个只包含0或1的二维数组（相当于矩阵）。可以将矩阵中的一行或一列中所有值进行反转（比如：将0变为1，将1变为0）
//最终使得矩阵中每行看成是一个二进制表示的数，各行所代表的数求和，最大化。

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int n=A.size(),m=A[0].size();
        for(int i=0;i<n;++i) {
            if(A[i][0] == 1) continue; //枚举所有行，如果该行中最左边的元素为0，那么显示进行反转，值会变大
            for(int j=0;j<m;++j) {
                A[i][j]=(A[i][j]==0?1:0);
            }
        }
        for(int i=0;i<m;++i) {
            int sum=0;
            for(int j=0;j<n;++j) {
                sum+=A[j][i];
            }
            if(sum>=(n+1)/2) continue; //枚举所有列，如果当前列的值为1的元素个数超过总行数的一半，则说明不用反转
            for(int j=0;j<n;++j) {
                A[j][i]=(A[j][i]==0?1:0);
            }
        }
        int res=0; //最终，进行求和
        for(int i=0;i<n;++i) {
            int val=0,mul=1;
            for(int j=m-1;j>=0;--j) {
                val+=mul*A[i][j];
                mul*=2;
            }
            res+=val;
        }
        return res;
    }
};
