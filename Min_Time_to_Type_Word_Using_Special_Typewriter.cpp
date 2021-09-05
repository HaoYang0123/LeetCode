// Leetcode 1974

class Solution {
public:
    int minTimeToType(string word) {
        int res = 0;
        char cur = 'a';
        for(int i=0; i<word.length(); ++i) {
            int c1 = int(word[i]-cur);
            if(c1 < 0) c1 = -c1;
            int c2 = 26-c1;
            res += min(c1, c2)+1;
            cur = word[i];
        }
        return res;
    }
};
