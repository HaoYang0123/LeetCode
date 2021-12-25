// Leetcode 2109

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        int spa_idx = 0;
        for(int i=0; i<s.length(); ++i) {
            if(spa_idx < spaces.size() && i == spaces[spa_idx]) {
                res += " ";
                ++spa_idx;
            }
            res += s[i];
        }
        return res;
    }
};
