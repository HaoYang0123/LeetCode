//Leetcode 1486

class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> data(n, 0);
        for(int i=0;i<n;++i) data[i] = start + 2*i;
        int res = 0;
        for(int i=0;i<n;++i) res ^= data[i];
        return res;
    }
};
