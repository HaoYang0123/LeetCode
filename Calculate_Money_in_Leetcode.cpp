// Leetcode 1716

class Solution {
public:
    int totalMoney(int n) {
        int res = 0;
        int cur_m = 0, cur_m2 = 0;
        for(int i=0;i<n;++i) {
            if(i % 7 == 0) {
                cur_m++;
                res += cur_m;
                cur_m2 = cur_m;
            }
            else{
                cur_m2++;
                res += cur_m2;
            }
        }
        return res;
    }
};
