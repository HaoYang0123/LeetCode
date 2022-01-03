// Leetcode 1941

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> c2n;
        for(int i=0; i<s.length(); ++i) c2n[s[i]]++;
        int c = 0;
        for(auto idx=c2n.begin(); idx!=c2n.end(); ++idx) {
            if(c == 0) c = idx->second;
            else if(c != idx->second) return false;
        }
        return true;
    }
};
