//Leetcode 1556

class Solution {
public:
    string thousandSeparator(int n) {
        if(n==0) return "0";
        string res = "";
        int cur_len = 0;
        while(n>0) {
            int bit = n%10;
            res += char('0'+bit);
            n /= 10;
            ++cur_len;
            if(cur_len % 3 == 0) res += ".";
        }
        if(res.length() > 0 && res.back() == '.') res = res.substr(0, res.length()-1);
        reverse(res.begin(), res.end());
        return res;
    }
};
