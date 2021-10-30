// Leetcode 2033
//将矩阵转成1维数组，然后排序，找到中位数，这样的话大家都变成中位数的时候，操作步骤是最小的。这是为何，我之前想到的是计算求和的均值，让他们都变为均值，才是最小的

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        int n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                v.push_back(grid[i][j]);
        if(v.size() == 1) return 0;
        sort(v.begin(), v.end());
        int mid = v[v.size()/2];
        int res = 0;
        for(int i=0;i<v.size();++i) {
            if(abs(v[i]-mid) % x != 0) return -1;
            res += abs(v[i]-mid) / x;
        }
        return res;
    }
};
