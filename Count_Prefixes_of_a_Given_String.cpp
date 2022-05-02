// Leetcode 2255

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int res = 0;
        for(int i=0; i<words.size(); ++i) {
            if(is_prefix(words[i], s)) ++res;
        }
        return res;
    }
    
    inline bool is_prefix(string & word, string & s) {
        int i=0;
        for(; i<word.length() && i<s.length(); ++i) {
            if(s[i] != word[i]) return false;
        }
        return i>=int(word.length());
    }
};
