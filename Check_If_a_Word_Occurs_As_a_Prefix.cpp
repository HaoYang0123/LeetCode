//Leetcode 1455

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string cur_word = "";
        int res = 0;
        for(int i=0;i<sentence.length();++i) {
            if(sentence[i] != ' ') cur_word += sentence[i];
            else {
                ++res;
                if(is_prefix(cur_word, searchWord)) return res;
                cur_word = "";
            }
        }
        ++res;
        if(is_prefix(cur_word, searchWord)) return res;
        return -1;
    }
    
    bool inline is_prefix(string & a, string & b) {
        if(a.length() < b.length()) return false;
        for(int i=0;i<b.length();++i) {
            if(a[i] != b[i]) return false;
        }
        return true;
    }
};
