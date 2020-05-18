//Leetcode 1451

class Solution {
public:
    string arrangeWords(string text) {
        map<int,vector<string>> len2vec;
        string cur = "";
        for(int i=0;i<text.length();++i) {
            if(i==0) cur += (char)('a' + int(text[i]-'A'));
            else {
                if(text[i] != ' ') cur += text[i];
                else {
                    len2vec[cur.length()].push_back(cur);
                    cur = "";
                }
            }
        }
        if(cur != "") len2vec[cur.length()].push_back(cur);
        string res = "";
        for(auto ind = len2vec.begin(); ind != len2vec.end(); ++ind) {
            vector<string> & s = ind->second;
            for(int i=0;i<s.size();++i) {
                if(res == "") s[i][0] = (char)('A' + int(s[i][0]-'a'));
                res += s[i] + ' ';
            }
        }
        res = res.substr(0, res.length()-1);
        return res;
    }
};
