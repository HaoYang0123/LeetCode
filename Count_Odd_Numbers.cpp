//Leetcode 1523

class Solution {
public:
    int countOdds(int low, int high) {
        int res = high-low+1;
        int remain = res % 2;
        res /= 2;
        if(remain == 0) return res;
        if(low % 2 != 0) ++res;
        return res;
    }
};
