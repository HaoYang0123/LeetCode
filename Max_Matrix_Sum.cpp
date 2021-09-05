// Leetcode 1975
//此题思路比较简单，就是如果非正数（负数和0）的数量为偶数，那么直接就可以通过不停地两两置换，全部转成正数；
//否则，那么找到最小的绝对值数（可能是正、可能是负），然后最后置换得到的此数成为负数，这样求和会最大。
//有几个坑：1）非正数，当时只考虑了负数，0也得考虑；2）当时只考虑了负数中绝对值最小的数，其实也得把正数考虑进去

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long res = 0;
        long long min_neg = -1000000;
        int min_num = 0;
        for(int i=0;i<matrix.size();++i) {
            for(int j=0;j<matrix[0].size();++j) {
                if(matrix[i][j] <= 0) {
                    min_neg = max(min_neg, (long long)(matrix[i][j]));
                    min_num += 1;
                }
                else {
                    min_neg = max(min_neg, -(long long)(matrix[i][j]));
                }
                res += abs((long long)(matrix[i][j]));
            }
        }
        //cout<<res<<"\t"<<min_neg<<"\t"<<min_num<<endl;
        if(min_num % 2 == 0) return res;
        res += 2*min_neg;
        return res;
    }
};
