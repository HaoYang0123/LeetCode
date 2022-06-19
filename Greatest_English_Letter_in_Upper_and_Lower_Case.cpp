// Leetcode 2309

class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> ss;
        for(int i=0; i<s.length(); ++i) {
            ss.insert(s[i]);
        }
        string res = "";
        for(auto idx = ss.begin(); idx != ss.end(); ++idx) {
            if(*idx >= 'a' && *idx <= 'z') continue;
            char c = *idx;
            string newc = "";
            newc += c;
            char small_c = char('a' + int(c - 'A'));
            if(ss.find(small_c) != ss.end()) {
                if(res == "") res = newc;
                else {
                    res = max(res, newc);
                }
            }
        }
        return res;
    }
};
