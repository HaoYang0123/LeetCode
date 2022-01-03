// Leetcode 2124

class Solution {
public:
    bool checkString(string s) {
        int ai = -1, bi = INT_MAX;
        for(int i=0; i<s.length(); ++i) {
            if(s[i] == 'a') ai = max(ai, i);
            else bi = min(bi, i);
        }
        return ai < bi;
    }
};
