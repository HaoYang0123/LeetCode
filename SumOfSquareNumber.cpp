class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i = 0; i <= sqrt(c); ++i) {
            int key = c - i * i;
            if(key >= c + 1 || key < 0) continue;
            int ss = sqrt(key);
            if(ss * ss == key) return true;
        }
        return false;
    }
};
