//Leetcode 1513

class Solution {
public:
    int MOD;
    int numSub(string s) {
        MOD = 1000000007;
        long long res = 0;
        int c = 0;
        for(int i=0;i<s.length();++i) {
            if(s[i] == '1') {
                ++c;
            }
            else {
                res = (res + get_num(c)) % MOD;
                c = 0;
            }
        }
        res = (res + get_num(c)) % MOD;
        return res;
    }
    inline long long get_num(int n) {
        long long res = ((long long)n * (n+1)) / 2;
        return res % MOD;
    }
};
