//Leetcode 1646

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0) return 0;
        int res = 1;
        vector<int> data(n+1, 0);
        data[1] = 1;
        for(int i=2;i<=n;++i) {
            if(i%2 == 0) data[i] = data[i/2];
            else data[i] = data[i/2] + data[i/2+1];
            res = max(res, data[i]);
        }
        return res;
    }
};
