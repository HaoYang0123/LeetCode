// Leetcode 1935

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int res = 0;
        text += " ";
        string cur_word = "";
        vector<bool> blv(26, false);
        for(int i=0; i<brokenLetters.length(); ++i) blv[int(brokenLetters[i]-'a')] = true;
        for(int i=0; i<text.length(); ++i) {
            if(text[i] != ' ') cur_word += text[i];
            else {
                if(can_type(cur_word, blv)) ++res;
                cur_word = "";
            }
        }
        return res;
    }
    
    bool can_type(string & word, vector<bool> & blv) {
        for(int i=0; i<word.length(); ++i) {
            if(blv[int(word[i]-'a')]) return false;
        }
        return true;
    }
};
