// Leetcode 2114

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int res = 0;
        for(int i=0; i<sentences.size(); ++i) {
            res = max(res, get_word_num(sentences[i]));
        }
        return res;
    }
    
    inline int get_word_num(string& sent) {
        int kong = 0;
        for(int i=0; i<sent.length(); ++i) {
            if(sent[i] == ' ') ++kong;
        }
        return kong+1;
    }
};
