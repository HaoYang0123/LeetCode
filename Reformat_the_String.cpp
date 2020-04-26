//Leetcode 1417

class Solution {
public:
    string reformat(string s) {
        vector<int> dig_vec, char_vec;
        for(int i=0;i<s.length();++i) {
            if(s[i] >= '0' && s[i] <= '9') dig_vec.push_back(s[i]);
            else char_vec.push_back(s[i]);
        }
        int dig_num = dig_vec.size(), char_num = char_vec.size();
        if(abs(dig_num - char_num) > 1) return "";
        string res = "";
        int di = 0, ci = 0;
        if(dig_num > char_num) {
            res += dig_vec[di++];
        }
        while(di < dig_num && ci < char_num) {
            res += char_vec[ci++];
            res += dig_vec[di++];
        }
        if(ci < char_num) res += char_vec[ci++];
        return res;
    }
};
