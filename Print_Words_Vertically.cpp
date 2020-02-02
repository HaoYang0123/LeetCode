//Leetcode 1324

class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;
        split_string(s, words);
        vector<int> index(words.size(), 0);
        vector<string> res;
        while(true) {
            string cur_word = "";
            update_index(words, index, cur_word);
            if(cur_word == "") break;
            res.push_back(cur_word);
        }
        return res;
    }
    
    inline void update_index(vector<string> & words, vector<int> & index, string & cur_word) {
        for(int i = 0; i < index.size(); ++i) {
            int ind = index[i];
            if(ind < words[i].length()) cur_word += words[i][ind];
            else cur_word += ' ';
            ++index[i];
        }
        int i = cur_word.length()-1;
        while(i>=0 && cur_word[i] == ' ') --i;
        cur_word = cur_word.substr(0, i+1);
    }
    
    inline void split_string(string & s, vector<string> & words) {
        string cur_word = "";
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] != ' ') {
                cur_word += s[i];
            }
            else {
                words.push_back(cur_word);
                cur_word = "";
            }
        }
        if(cur_word != "") words.push_back(cur_word);
    }
};
