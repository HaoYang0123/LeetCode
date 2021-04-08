// Leetcode 1816

class Solution {
public:
    string truncateSentence(string s, int k) {
        int c = 0;
        string res = "";
        string cur = "";
        for(int i=0;i<s.length();++i) {
            if(s[i] != ' ') cur += s[i];
            else {
                c += 1;
                res += cur + " ";
                cur = "";
                if(c >= k) break;
            }
        }
        if (cur != "" && c < k) res += cur + " ";
        return res.substr(0, res.length()-1);
    }
};
