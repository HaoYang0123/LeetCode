//Leetcode 1684

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, bool> m2;
        for(int i=0; i<allowed.length(); ++i) m2[allowed[i]] = true;
        int res = 0;
        for(int i=0; i<words.size(); ++i) {
            if(is_consistent(words[i], m2)) ++res;
        }
        return res;
    }
    
    inline bool is_consistent(string & str, unordered_map<char, bool> m2) {
        for(int i=0; i<str.length(); ++i) {
            if(m2.find(str[i]) == m2.end()) return false;
        }
        return true;
    }
};
