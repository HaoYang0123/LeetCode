// Leetcode 2017

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if(n == 1) return 0;
        vector<long long> dp_one(n, 0); //dp_one[i]表示在第1行中从i至最右边的累积和
        vector<long long> dp_two(n, 0); //dp_two[i]表示在第2行中从最左边至i的累积和
        dp_one[n-1] = (long long)grid[0][n-1];
        for(int i=n-2; i>=0; --i) dp_one[i] = dp_one[i+1] + grid[0][i];
        dp_two[0] = (long long)grid[1][0];
        for(int i=1; i<n; ++i) dp_two[i] = dp_two[i-1] + grid[1][i];
        long long res = min(dp_one[1], dp_two[n-2]);
        for(int i=1;i<n-1;++i) 
            res = min(res, max(dp_one[i+1], dp_two[i-1]));
        return res;
    }
};
