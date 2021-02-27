// Leetcode 1752

class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> m = nums;
        for(int i=0;i<nums.size();++i) m.push_back(nums[i]);
        int max_len = 0;
        int cur_value = INT_MIN, cur_len = 0;
        for(int i=0;i<m.size();++i) {
            if(m[i] >= cur_value) {
                ++cur_len;
                cur_value = m[i];
            }
            else {
                max_len = max(max_len, cur_len);
                cur_value = m[i];
                cur_len = 1;
            }
        }
        max_len = max(max_len, cur_len);
        return max_len >= nums.size();
    }
};
