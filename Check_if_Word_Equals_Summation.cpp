// Leetcode 1880

class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return get_digit(firstWord) + get_digit(secondWord) == get_digit(targetWord);
    }
    
    inline int get_digit(string & word) {
        int res = 0;
        for(int i=0; i<word.length(); ++i) {
            res = res * 10 + int(word[i]-'a');
        }
        return res;
    }
};
