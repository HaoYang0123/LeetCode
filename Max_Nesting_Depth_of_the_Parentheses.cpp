//Leetcode 1614

class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int cur_left = 0, cur_right = 0;
        for(int i=0; i<s.length(); ++i) {
            if(s[i] == '(') ++cur_left;
            else if(s[i] == ')') ++cur_right;
            res = max(res, cur_left-cur_right);
        }
        return res;
    }
};
