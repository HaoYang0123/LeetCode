// Leetcode 1911
//把它看成股票买卖问题，多次购买（不能同时购买多支股票，即买了后一定得卖掉，才能再次买）；
//那么就相当于在高价买、低价卖（与股票买卖相返）
//比如：[6,2,1,4,5,7,4,2,5], 那么相当于6-1+7-2+5，6是高价买、1是低价卖、...

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long res = 0;
        vector<int> final_vec;
        for(int i=0; i<nums.size()-1; ++i) {
            if(final_vec.size() % 2 == 0) {  //偶数索引，找最大的值
                if(nums[i] >= nums[i+1]) {
                    final_vec.push_back(nums[i]);
                }
            }
            else {  //奇数索引，找最小的值
                if(nums[i] <= nums[i+1]) {
                    final_vec.push_back(nums[i]);
                }
            }
        }
        if(final_vec.size() % 2 == 0) final_vec.push_back(nums.back());  //将最后一个元素加入其中
        for(int i=0; i<final_vec.size(); ++i) {
            if (i % 2 == 0) res += (long long)(final_vec[i]);
            else res -= (long long)(final_vec[i]);
        }
        return res;
    }
};
