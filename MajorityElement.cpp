//找出现次数超过⌊ n/2 ⌋的元素

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int r = nums[0], c = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == r) ++c;
            else {
                --c;
                if(c == 0) {
                    r = nums[i];
                    c = 1;
                }
            }
        }
        return r;
    }
};
