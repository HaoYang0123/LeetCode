// Leetcode 443

class Solution {
public:
    int compress(vector<char>& chars) {
        int res = 0;
        char cur = chars[0];
        ++res;
        int cur_num = 1;
        for(int i=1; i<chars.size(); ++i) {
            if(chars[i] == cur) ++cur_num;
            else {
                if(cur_num > 1) {
                    string ntmp = to_string(cur_num);
                    for(int j=0; j<ntmp.length(); ++j) chars[res++] = ntmp[j];
                }
                cur_num = 1;
                cur = chars[i];
                chars[res++] = cur;
            }
        }
        if(cur_num > 1) {
            string ntmp = to_string(cur_num);
            for(int j=0; j<ntmp.length(); ++j) chars[res++] = ntmp[j];
        }
        return res;
    }
};
