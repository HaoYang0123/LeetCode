// Leetcode 2220

class Solution {
public:
    int minBitFlips(int start, int goal) {
        vector<int> sbit = int2bit(start);
        vector<int> gbit = int2bit(goal);
        int res = 0;
        int i=0;
        for(; i<sbit.size() && i<gbit.size(); ++i) {
            if(sbit[i] != gbit[i]) ++res;
        }
        for(;i<sbit.size(); ++i) {
            if(sbit[i] == 1) ++res;
        }
        for(;i<gbit.size(); ++i) {
            if(gbit[i] == 1) ++res;
        }
        return res;
    }
    
    inline vector<int> int2bit(int v) {
        vector<int> bit;
        while(v > 0) {
            bit.push_back(v % 2);
            v /= 2;  //0101   111
        }
        return bit;
    }
};
