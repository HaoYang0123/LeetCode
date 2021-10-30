// Leetcode 2024
//滑动窗口

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int res = 0;
        int t = 0, f = 0;
        int left = 0, right = 0;
        while(right < answerKey.length()) {
            if(answerKey[right] == 'T') ++t;
            else ++f;
            while(min(t, f) > k) {
                if(answerKey[left] == 'T') --t;
                else --f;
                ++left;
            }
            res = max(res, right-left+1);
            ++right;
        }
        return res;
    }
};
