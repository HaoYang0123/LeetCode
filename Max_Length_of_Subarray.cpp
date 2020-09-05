//Leetcode 1567

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int neg_num = 0;
        int res = 0, cur_res = 0;
        for(int i=0;i<nums.size();++i) { //从左往右扫描，比如:[1,2,-2,-1,3,-1]，得到最大的为5（序列为[1,2,-2,-1,3]）
            if(nums[i] < 0) {
                ++neg_num;
                ++cur_res;
                if(neg_num % 2 == 0) 
                    res = max(res, cur_res);
            }
            else if(nums[i] > 0) {
                ++cur_res;
                if(neg_num % 2 == 0)
                    res = max(res, cur_res);
            }
            else {
                neg_num = 0;
                cur_res = 0;
            }
        }
        neg_num = 0;
        cur_res = 0;
        for(int i=nums.size()-1;i>=0;--i) { //从右往左扫描，比如：[-1,-2,-3,2,3]，得到最大的为4（序列为[-2,-3,2,3]）
            if(nums[i] < 0) {
                ++neg_num;
                ++cur_res;
                if(neg_num % 2 == 0) 
                    res = max(res, cur_res);
            }
            else if(nums[i] > 0) {
                ++cur_res;
                if(neg_num % 2 == 0)
                    res = max(res, cur_res);
            }
            else {
                neg_num = 0;
                cur_res = 0;
            }
        }
        return res;
    }
};
