// Leetcode 1832

class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.length() < 26) return false;
        vector<int> cc(26, 0);
        for(int i=0; i<sentence.length(); ++i) {
            cc[(int)(sentence[i]-'a')]++;
        }
        for(int i=0; i<26; ++i) {
            if(cc[i] == 0) return false;
        }
        return true;
    }
};
