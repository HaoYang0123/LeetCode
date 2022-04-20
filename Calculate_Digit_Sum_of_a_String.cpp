// Leetcode 2243

class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length()>k) {
            string new_s = "";
            string cur_s = "";
            for(int i=0; i<s.length(); ++i) {
                cur_s += s[i];
                if(cur_s.length() == k) {
                    int tmp = 0;
                    for(int j=0; j<cur_s.length(); ++j) {
                        tmp += int(cur_s[j]-'0');
                    }
                    new_s += to_string(tmp);
                    cur_s = "";
                }
            }
            if(cur_s.length() > 0) {
                int tmp = 0;
                for(int j=0; j<cur_s.length(); ++j) {
                    tmp += int(cur_s[j]-'0');
                }
                new_s += to_string(tmp);
            }
            s = new_s;
        }
        return s;
    }
};
