// Leetcode 2194

class Solution {
public:
    vector<string> cellsInRange(string s) {
        char c1 = s[0], c2 = s[3];
        char r1 = s[1], r2 = s[4];
        vector<string> res;
        int delta_c = int(c2-c1);
        int delta_r = int(r2-r1);
        for(int c=0; c<=delta_c; ++c) {
            for(int r=0; r<=delta_r; ++r) {
                char cur_c = char(c1+c);
                char cur_r = char(r1+r);
                //cout<<cur_c<<cur_r<<endl;
                string tmp="";
                tmp+=cur_c;
                tmp+=cur_r;
                res.push_back(tmp);
            }
        }
        return res;
    }
};
