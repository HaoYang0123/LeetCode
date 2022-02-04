// Leetcode 1624

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> left(26, -1);
        vector<int> right(26, -1);
        for(int i=0; i<s.length(); ++i) {
            int idx = int(s[i]-'a');
            if(left[idx] == -1) left[idx] = i;
        }
        for(int i=s.length()-1; i>=0; --i) {
            int idx = int(s[i]-'a');
            if(right[idx] == -1) right[idx] = i;
        }
        int res = -1;
        for(int i=0; i<26; ++i) {
            res = max(res, right[i]-left[i]-1);
        }
        return res;
    }
};
