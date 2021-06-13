// Leetcode 1869

class Solution {
public:
    bool checkZeroOnes(string s) {
        int one = 0, zero = 0;
        int cur_one = 0, cur_zero = 0;
        for(int i=0;i<s.length();++i) {
            if(s[i] == '1') {
                cur_zero = 0;
                ++cur_one;
                one = max(one, cur_one);
            }
            else {
                cur_one = 0;
                ++cur_zero;
                zero = max(zero, cur_zero);
            }
        }
        return one > zero;
    }
};
