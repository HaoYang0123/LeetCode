//Leetcode 1342

class Solution {
public:
    int numberOfSteps (int num) {
        int res = 0;
        while(num > 0) {
            ++res;
            if(num % 2 == 0) num /= 2;
            else --num;
        }
        return res;
    }
};
