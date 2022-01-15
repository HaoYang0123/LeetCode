// Leetcode 1895

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int maxK=min(n,m);
        int res = 1;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                for(int k=2; k<=maxK; ++k) {
                    if(i+k > n || j+k > m) break;
                    if(is_ok(grid, i, j, k)) {
                        res = max(res, k);
                    }
                }
            }
        }
        return res;
    }
    
    inline bool is_ok(vector<vector<int>> & grid, int i, int j, int k) {
        //cout<<i<<"\t"<<j<<"\t"<<k<<endl;
        int sum = 0;
        for(int p=i; p<i+k; ++p) {
            sum += grid[p][j];
        }
        //所有列
        for(int q=j+1; q<j+k; ++q) {
            int csum = 0;
            for(int p=i; p<i+k; ++p) csum += grid[p][q];
            if(csum != sum) return false;
        }
        //所有行
        for(int p=i; p<i+k; ++p) {
            int csum = 0;
            for(int q=j; q<j+k; ++q) csum += grid[p][q];
            if(csum != sum) return false;
        }
        //对角线
        int p=i, q=j, sum1=0, sum2=0;
        while(p<i+k) {
            sum1 += grid[p++][q++];
        }
        p = i;
        q = j+k-1;
        while(p<i+k) {
            sum2 += grid[p++][q--];
        }
        return sum1 == sum && sum2 == sum;
    }
};
