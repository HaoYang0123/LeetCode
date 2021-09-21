// Leetcode 2000

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0;
        while(i < word.length()) {
            if(word[i] == ch) break;
            ++i;
        }
        if(i == word.length()) return word;
        string seg = word.substr(0, i+1);
        reverse(seg.begin(), seg.end());
        return seg + word.substr(i+1);
    }
};
