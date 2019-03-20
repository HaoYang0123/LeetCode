//Leetcode 807
//mm[i]记录网格中第i行中的最大值，cc[i]记录网格中第i列中的最大值
//grid[i][j]的值可以增长到min(mm[i],cc[j])，这样保证更新得到的网格数据的mm和cc不变

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> mm(n,0), cc(n,0);
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                if(grid[i][j]>mm[i]) mm[i]=grid[i][j];
                if(grid[i][j]>cc[j]) cc[j]=grid[i][j];
            }
        }
        int res=0;
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                int c=min(mm[i],cc[j]);
                res+=(c-grid[i][j]);
            }
        }
        return res;
    }
};
