// Leetcode 2091

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int min_v = INT_MAX, min_idx = -1;
        int max_v = INT_MIN, max_idx = -1;
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i] > max_v) {
                max_v = nums[i];
                max_idx = i;
            }
            if(nums[i] < min_v) {
                min_v = nums[i];
                min_idx = i;
            }
        }
        int left_pos_min = min_idx+1;
        int right_pos_min = nums.size()-min_idx;
        int left_pos_max = max_idx+1;
        int right_pos_max = nums.size()-max_idx;
        int res = min(left_pos_min+right_pos_max, left_pos_max+right_pos_min);
        res = min(res, max(left_pos_min, left_pos_max));
        res = min(res, max(right_pos_min, right_pos_max));
        return res;
    }
};
