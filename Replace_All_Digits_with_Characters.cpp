// Leetcode 1844

class Solution {
public:
    string replaceDigits(string s) {
        string res = "";
        for(int i=0; i<s.length(); ++i) {
            if(i % 2 == 0) res += s[i];
            else {
                res += (char)(s[i-1] + (int)(s[i]-'0'));
            }
        }
        return res;
    }
};
