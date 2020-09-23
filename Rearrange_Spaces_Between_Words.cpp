//Leetcode 1592

class Solution {
public:
    string reorderSpaces(string text) {
        int emp_num = 0;
        vector<string> words;
        string cur_word = "";
        for(int i=0;i<text.length();++i) {
            if(text[i] == ' ') {
                ++emp_num;
                if(cur_word != "") words.push_back(cur_word);
                cur_word = "";
            }
            else cur_word += text[i];
        }
        if(emp_num == 0) return text;
        if(cur_word != "") words.push_back(cur_word);
        if(words.size() <= 1) {
            string res = "";
            if(words.size() == 1) res = words[0];
            for(int i=0;i<emp_num;++i) res += ' ';
            return res;
        }
        int eq = emp_num / (words.size() - 1);
        int extra = emp_num % (words.size() - 1);
        string emp_str = "";
        for(int i=0;i<eq;++i) emp_str += ' ';
        string res = "";
        for(int i = 0;i < words.size() - 1; ++i) {
            res += words[i] + emp_str;
        }
        res += words.back();
        for(int i=0;i<extra;++i) res += ' ';
        return res;
    }
};
