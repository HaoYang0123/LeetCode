//Leetcode 1573

class Solution {
public:
    int numWays(string s) {
        int MOD = 1000000007;
        int one_num = 0; //记录1的数量
        for(int i=0;i<s.length();++i) {
            if(s[i] == '1') ++one_num;
        }
        if(one_num % 3 != 0) return 0; //如果1的数量不是3的倍数，很显然找不到切割方法
        if(one_num == 0) { //如果字符串s全部是0，那么切割方法就是C(n-1,2)，n是s的长度
            return get_C((long long)(s.length()-1)) % MOD;
        }
        long long a = 0, b = 0; //a和b分别记录第1个和第2个切割位置的数量
        int a1 = one_num / 3, b1 = 2 * a1;
        int c = 0;
        for(int i=0;i<s.length();++i) {
            if(s[i] == '1') {
                ++c;
            }
            if(c == a1) ++a; //当c等于a1，则第1个切割位置数量+1
            else if(c == b1) ++b; //当c等于b1，则第2个切割位置数量+1
        }
        return ((a % MOD) * (b % MOD)) % MOD;
    }
    
    inline long long get_C(long long n) {
        if(n % 2 == 0) {
            return n / 2 * (n-1);
        }
        else {
            return (n-1) / 2 * n;
        }
    }
};
