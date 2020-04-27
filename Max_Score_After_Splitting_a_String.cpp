//Leetcode 1422

class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int all_one_num = 0;
        for(int i=0;i<n;++i) {
            if(s[i] == '1') ++all_one_num;
        }
        int cur_zero_num = 0, cur_one_num = 0;
        int res = 0;
        for(int i=0;i<n-1;++i) { //注意：是n-1，因为不能到n，不然right substring为空
            if(s[i] == '0') ++cur_zero_num;
            else ++cur_one_num;
            res = max(res, cur_zero_num + (all_one_num - cur_one_num));
        }
        return res;
    }
};
