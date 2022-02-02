// Leetcode 2138

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        string cur_str = "";
        for(int i=0; i<s.length(); ++i) {
            cur_str += s[i];
            if(cur_str.length() == k) {
                res.push_back(cur_str);
                cur_str = "";
            }
        }
        if(cur_str.length() > 0) {
            while(cur_str.length() < k) cur_str += fill;
            res.push_back(cur_str);
        }
        return res;
    }
};
