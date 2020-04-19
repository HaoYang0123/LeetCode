//Leetcode 1405
//判断a，b，c当前值，找最大的那个，当前字符串就添加该字符。
//当然，得考虑至res[-1]和res[-2]对应的字符是否，与添加字符一样。如果一样，那么就找到剩余两值的大者

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        int l = a+b+c;
        while(res.length() < l) {
            if(a>=b && a>=c) {
                if(check(res, 'a')) {
                    res += 'a';
                    --a;
                }
                else{
                    if(b==0 && c==0) break;
                    if(b>=c) {
                        res += 'b';
                        --b;
                    }
                    else {
                        res += 'c';
                        --c;
                    }
                }
            }
            else if(b>=a && b>=c) {
                if(check(res, 'b')) {
                    res += 'b';
                    --b;
                }
                else {
                    if(a==0 && c==0) break;
                    if(a>c) {
                        res += 'a';
                        --a;
                    }
                    else {
                        res += 'c';
                        --c;
                    }
                }
            }
            else if(c>=a && c>=b) {
                if(check(res, 'c')) {
                    res += 'c';
                    --c;
                }
                else {
                    if(a==0 && b==0) break;
                    if(a>b) {
                        res += 'a';
                        --a;
                    }
                    else {
                        res += 'b';
                        --b;
                    }
                }
            }
        }
        return res;
    }
    
    inline bool check(string & res, char c) {
        if(res.length() < 2) return true;
        if(res[res.length()-1] != c) return true;
        if(res[res.length()-2] != c) return true;
        return false;
    }
};
