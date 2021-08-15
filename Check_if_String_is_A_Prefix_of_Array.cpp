// Leetcode 1961

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int si = 0;
        int wi = 0;
        for(; wi < words.size() && si < s.length(); ++wi) {
            for(int i=0; i<words[wi].size(); ++i) {
                if(si >= s.length() || words[wi][i] != s[si]) return false;
                ++si;
            }
        }
        return si >= s.length();
    }
};
