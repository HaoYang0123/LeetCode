// Leetcode 1859

class Solution {
public:
    string sortSentence(string s) {
        string cur_s = "";
        map<int, string> pos2str;
        for(int i=0; i<s.length(); ++i) {
            if(s[i] != ' ') cur_s += s[i];
            else {
                string only_s = "";
                int pos = get_pos(cur_s, only_s);
                pos2str[pos] = only_s;
                cur_s = "";
            }
        }
        if(cur_s != "") {
            string only_s = "";
            int pos = get_pos(cur_s, only_s);
            pos2str[pos] = only_s;
        }
        string res = "";
        for(auto ind = pos2str.begin(); ind != pos2str.end(); ++ind) {
            res += ind->second + " ";
        }
        if(res.length() != 0) res = res.substr(0, res.length()-1);
        return res;
    }
    
    inline int get_pos(string & s, string & only_s) {
        string dig = "";
        for(int i=0; i<s.length(); ++i) {
            if(s[i] >= '0' && s[i] <= '9') dig += s[i];
            else only_s += s[i];
        }
        return atoi(dig.c_str());
    }
};
