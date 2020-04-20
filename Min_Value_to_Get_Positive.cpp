//Leetcode 1413

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0, min_sum = 0;
        for(auto num : nums) {
            sum += num;
            min_sum = min(min_sum, sum);
        }
        return -min_sum + 1;
    }
};
