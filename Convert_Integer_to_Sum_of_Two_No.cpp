//Leetcode 1317

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res(2,0);
        for(int i=1;i<=n/2;++i) {
            if(is_no_zero(i) && is_no_zero(n-i)) {
                res[0] = i; res[1] = n-i;
                return res;
            }
        }
        return res;
    }
    
    inline bool is_no_zero(int n) {
        while(n > 0) {
            int bit = n%10;
            if(bit == 0) return false;
            n /= 10;
        }
        return true;
    }
};
