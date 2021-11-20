// Leetcode 2068

class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> c1(26, 0);
        vector<int> c2(26, 0);
        get_count(word1, c1);
        get_count(word2, c2);
        for(int i=0; i<26; ++i)
            if(abs(c1[i]-c2[i]) > 3) return false;
        return true;
    }
    
    inline void get_count(string & word, vector<int> & count) {
        for(int i=0; i<word.length(); ++i) {
            count[int(word[i]-'a')]++;
        }
    }
};
