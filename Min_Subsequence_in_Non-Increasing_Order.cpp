//Leetcode 1403

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i=0;i<nums.size();++i) sum += nums[i];
        vector<int> res;
        int cur_sum = 0;
        int half_value = sum / 2;
        for(int i=nums.size()-1;i>=0;--i) {
            res.push_back(nums[i]);
            cur_sum += nums[i];
            if(cur_sum > half_value) break;
        }
        return res;
    }
};
