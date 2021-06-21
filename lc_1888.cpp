// leetcode 1888

class Solution {
public:
    int minFlips(string s) {
        string new_s = s + s;
        int window_size = s.length();
        int res = s.length(), cur_res = 0;
        for(int i=0; i<window_size; ++i) {
            if(i % 2 == 0 && new_s[i] == '0') ++cur_res;
            else if(i % 2 == 1 && new_s[i] == '1') ++cur_res;
        }
        res = min(res, min(cur_res, window_size-cur_res));  //0101与1010的比较
        for(int i=1; i<=new_s.length()-window_size; ++i) {
            int new_i = i-1+window_size;
            int old_i = i-1;
            if(new_i % 2 == 0 && new_s[new_i] == '0') ++cur_res;
            else if(new_i % 2 == 1 && new_s[new_i] == '1') ++cur_res;
            if(old_i % 2 == 0 && new_s[old_i] == '0') --cur_res;
            else if(old_i % 2 == 1 && new_s[old_i] == '1') --cur_res;
            res = min(res, min(cur_res, window_size-cur_res));
        }
        return res;
    }
};
