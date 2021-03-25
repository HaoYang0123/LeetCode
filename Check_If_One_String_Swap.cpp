// Leetcode 1790

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> diff;
        int n = s1.length();
        for(int i=0;i<n;++i) {
            if(s1[i] != s2[i]) diff.push_back(i);
        }
        if(diff.size() > 2 || diff.size() == 1) return false;
        if(diff.size() == 0) return true;
        int a=diff[0], b=diff[1];
        if(s1[a] == s2[b] && s1[b] == s2[a]) return true;
        return false;
    }
};
