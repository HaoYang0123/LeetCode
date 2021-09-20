// Leetcode 1991

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); ++i) sum += nums[i];
        int cur_sum = 0;
        for(int i=0; i<nums.size(); ++i) {
            if(sum - nums[i] - cur_sum == cur_sum) return i;
            cur_sum += nums[i];
        }
        return -1;
    }
};
