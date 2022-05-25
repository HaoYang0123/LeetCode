// Leetcode 2278

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int num = 0;
        for(int i=0; i<s.length(); ++i) {
            if(s[i] == letter) ++num;
        }
        return num * 100 / int(s.length());
    }
};
