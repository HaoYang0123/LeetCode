// Leetcode 1981
//bitset用法，bs[i]记录从第0行至第i行的所有求和，如果bs[i][k]=1，那么表示求和集合中包含等于k的情况
//最后，只用判断bs[n-1]中的所有求和，哪个和target是最接近的

class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();
        bitset<5000> bs[n];
        for(int i=0; i<m; ++i) bs[0][mat[0][i]] = 1;
        for(int i=1; i<n; ++i) {
           for(int j=0; j<m; ++j) {
               bs[i] |= bs[i-1] << mat[i][j];
           } 
        }
        
        int res = INT_MAX;
        for(int i=n;i<=4900; ++i) {
            if(bs[n-1][i] == 1) {
                res = min(res, abs(target - i));
            }
        }
        return res;
    }
};
