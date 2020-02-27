//Leetcode 1347

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> c1(26, 0);
        vector<int> c2(26, 0);
        for(int i=0;i<s.length();++i) {
            c1[int(s[i]-'a')]++;
            c2[int(t[i]-'a')]++;
        }
        int res = 0;
        for(int i=0;i<26;++i) {
            res += abs(c1[i] - c2[i]);
        }
        return res/2;
    }
};
