// Leetcode 2129

class Solution {
public:
    string capitalizeTitle(string title) {
        string res = "";
        vector<string> words;
        title += ' ';
        string cur = "";
        for(int i=0; i<title.length(); ++i) {
            if(title[i] != ' ') {
                if(title[i] >= 'a' && title[i] <= 'z')
                    cur += title[i];
                else
                    cur += char('a' + int(title[i] - 'A'));
            }
            else {
                words.push_back(cur);
                cur = "";
            }
        }
        for(int i=0; i<words.size(); ++i) {
            string neww = get_word(words[i]);
            res += neww + ' ';
        }
        return res.substr(0, res.length()-1);
    }
    
    inline string get_word(string & word) {
        if(word.length() <= 2) return word;
        word[0] = char('A' + int(word[0] - 'a'));
        return word;
    }
};
