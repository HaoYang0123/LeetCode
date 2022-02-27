// Leetcode 2185

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int  res = 0;
        for(int i=0; i<words.size(); ++i) {
            if(is_pref(words[i], pref)) ++res;
        }
        return res;
    }
    
    inline bool is_pref(string & word, string & pref) {
        if(word.length() < pref.length()) return false;
        for(int i=0; i<pref.length(); ++i)
        {
            if(word[i] != pref[i]) return false;   
        }
        return true;
    }
};
