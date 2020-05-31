//Leetcode 1464

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_value = 0, max_index = -1;
        for(int i=0;i<nums.size();++i) {
            if(nums[i] > max_value) {
                max_value = nums[i];
                max_index = i;
            }
        }
        int max_value2 = 0;
        for(int i=0;i<nums.size();++i) {
            if(i == max_index) continue;
            if(nums[i] > max_value2) {
                max_value2 = nums[i];
            }
        }
        return (max_value-1)* (max_value2-1);
    }
};
