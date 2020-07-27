//Leetcode 1529

class Solution {
public:
    int minFlips(string target) {
        int res = 0;
        char cur = '0';
        for(int i=0;i<target.length();++i) {
            if(cur != target[i]) {
                ++res;
                cur = target[i];
            }
        }
        return res;
    }
};
