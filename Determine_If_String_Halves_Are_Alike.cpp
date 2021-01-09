// Leetcode 1704

class Solution {
public:
    bool halvesAreAlike(string s) {
        return get_vowel_num(s, 0, s.length()/2) == get_vowel_num(s, s.length()/2, s.length());
    }
    
    inline int get_vowel_num(string & s, int start, int end) {
        int res = 0;
        for(int i=start; i<end; ++i) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') ++res;
            else if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') ++res;
        }
        return res;
    }
};
