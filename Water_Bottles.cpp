//Leetcode 1518

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        int empty_num = numBottles;
        while(empty_num >= numExchange) {
            res += (empty_num / numExchange);
            empty_num = (empty_num / numExchange) + (empty_num % numExchange);
        }
        return res;
    }
};
