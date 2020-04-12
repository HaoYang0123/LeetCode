//Leetcode 1404

class Solution {
public:
    int numSteps(string s) {
        int res = 0;
        while(s != "1") {
            ++res;
            if(s[s.length()-1] == '1') { //奇数
                s = add_one(s);
            }
            else {
                s = s.substr(0, s.length()-1);
            }
        }
        return res;
    }
    
    inline string add_one(const string & s) {
        string res = "";
        int i = s.length() - 1;
        while(i>=0) {
            if(s[i] == '0') break;
            res += '0';
            --i;
        }
        res += '1';
        --i;
        while(i>=0) {
            res += s[i];
            --i;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
