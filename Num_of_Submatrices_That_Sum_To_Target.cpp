//Leetcode 1074
//O(N^2*M)的时间复杂度，虽然AC了，感觉时间复杂度还是有一点高。后面再思考一下别的思路
//当前思路是：将矩阵的求和问题转化为数组的求和问题
//dp[i][j]存储从矩阵matrix[i][0]至matrix[i][j]的求和，即列方向的和
//这样两个for循环(代码中的i和j)，则可以计算新的一维数组new_array，表示从(i+1)行按列求和至第j行
//在new_array一维数组中计算子数组求和等于target的数目，即意味着矩阵从matrix[i+1]至matrix[j]的求和为target的数目
//当前还得考虑矩阵直接从第0行求和的情况
//最终时间复杂度是：两层按行顺序的for循环(N^2)，在一维数组（数组元素数目是M）中以O(M)时间复杂度求解，得到时间复杂度为O(N^2*M)

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0)); //dp[i][j]表示从matrix[i][0]至matrix[i][j](列的顺序)的求和
        int res = 0;
        for(int i=0;i<m;++i) {
            dp[0][i] = matrix[0][i];
        }
        for(int i=1;i<n;++i) {
            for(int j=0;j<m;++j) {
                dp[i][j] += matrix[i][j] + dp[i-1][j];
            }
        }
        for(int i=0;i<n;++i) {
            res += numInArray(dp[i], target);
            for(int j=i+1;j<n;++j) {
                vector<int> new_array(m,0);
                for(int k=0;k<m;++k) new_array[k] = dp[j][k]-dp[i][k];
                res += numInArray(new_array, target);
            }
        }
        return res;
    }
    
    int numInArray(vector<int> & a, int target) { //在一个一维数组中，找子数组求和=target的数目（时间复杂度O(N)）
        unordered_map<int, int> mm; //mm[key]表示前缀和为key出现的次数
        int cur_sum = 0, res = 0;
        for(int i=0;i<a.size();++i) {
            cur_sum += a[i];
            if(cur_sum == target) ++res;
            res += mm[cur_sum-target];
            mm[cur_sum]++;
        }
        return res;
    }
};
