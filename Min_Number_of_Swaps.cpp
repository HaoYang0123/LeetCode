//Leetcode 1963

class Solution {
public:
    int minSwaps(string s) {
        int c = 0;
        for(int i=0; i<s.length(); ++i) {
            if(s[i] == '[') ++c;
            if(s[i] == ']') {
                if(c>0) --c;
            }
        }
        return (c+1)/2;
    }
};
