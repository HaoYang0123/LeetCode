// Leetcode 2264

class Solution {
public:
    string largestGoodInteger(string num) {
        string res = "";
        char c = num[0];
        int cnum = 1;
        num += '#';
        for(int i=1; i<num.length(); ++i) {
            if(num[i] == c) {
                ++cnum;
                if(cnum >= 3) {
                    string tmp = "";
                    for(int j=0; j<3; ++j) tmp += c;
                    res = max(res, tmp);
                }
            }
            else {
                c = num[i];
                cnum = 1;
            }
        }
        return res;
    }
};
