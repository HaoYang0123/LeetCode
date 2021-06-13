// Leetcode 1887

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, cur = 0, cur_v = nums[0];
        for(int i=1; i<nums.size(); ++i) {
            if(nums[i] == cur_v) {
                res += cur;
            }
            else{
                ++cur;
                res += cur;
                cur_v = nums[i];
            }
        }
        return res;
    }
};
