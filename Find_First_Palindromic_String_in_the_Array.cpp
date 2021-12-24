// Leetcode 2108

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0; i<words.size(); ++i)
            if(is_pal(words[i])) return words[i];
        return "";
    }
    
    inline bool is_pal(string & word) {
        for(int i=0; i<word.length()/2; ++i) {
            if(word[i] != word[word.length()-1-i]) return false;
        }
        return true;
    }
};
