// Leetcode 1800

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = 0;
        int cur = 0, cur_res = 0;
        for(int i=0;i<nums.size();++i) {
            if(nums[i] > cur) {
                cur_res += nums[i];
            }
            else {
                res = max(res, cur_res);
                cur = nums[i];
                cur_res = cur;
            }
            cur = nums[i];
        }
        res = max(res, cur_res);
        return res;
    }
};
