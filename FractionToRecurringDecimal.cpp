//得到小数a/b的字符串，如果是循环，使用括号括起来，比如2/3=0.(6)，后面有无穷个6
//小数值的计算：3/7，第一位等于30/7=4，后续是30%7=2，然后第二位等于20/7=2，则值应该是0.42....，保留余数在字符串的位置，如果值已经在之前计算的余数内，那么出现了循环

class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        string res = "";
        if(numerator == 0) return "0";
        if(numerator < 0 ^ denominator < 0) res = "-";
        long long a = abs(numerator), b = abs(denominator);
        res += to_string(a / b);
        if(a % b == 0) return res;
        res += ".";
        a = a % b;
        unordered_map<long long, int> mm;
        for(long long r = a; r; r %= b) {
            if(mm[r] != NULL) {
                res.insert(mm[r], 1, '(');
                res += ')';
                return res;
            }
            mm[r] = res.length();
            r *= 10;
            res += to_string(r / b);
        }
        return res;
    }
};
