// Leetcode 1446

class Solution {
public:
    int maxPower(string s) {
        char c = ' ';
        int res = 0, cur = 1;
        s += '&';
        for(int i=0; i<s.length(); ++i) {
            if(s[i] != c) {
                res = max(res, cur);
                cur = 1;
                c = s[i];
            }
            else ++cur;
        }
        return res;
    }
};
