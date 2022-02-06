// Leetcode 2042

class Solution {
public:
    bool areNumbersAscending(string s) {
        int cur = 0;
        string cur_str = "";
        s += " ";
        for(int i=0; i<s.length(); ++i) {
            if(s[i] != ' ') {
                cur_str += s[i];
            }
            else {
                if(cur_str[0] >= '0' && cur_str[0] <= '9') {
                    int tmp = atoi(cur_str.c_str());
                    if(tmp <= cur) return false;
                    cur = tmp;
                }
                cur_str = "";
            }
        }
        return true;
    }
};
