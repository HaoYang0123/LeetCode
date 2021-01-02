// Leetcode 1695
//用两个指针，记录当前的subarray

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0, r = 0;
        int res = 0, cur_sum = 0;
        unordered_set<int> cur_array;
        while(r < nums.size()) {
            //cout<<l<<"\t"<<r<<"\t"<<cur_sum<<endl;
            if(cur_array.find(nums[r]) != cur_array.end()) { //如果当前元素在cur_array当前数组中，则需要从左数组中去掉元素
                cur_sum -= nums[l];
                cur_array.erase(nums[l]);
                ++l;  
            }
            else { //否则，可以将当前元素加入至cur_array当前数组中
                cur_array.insert(nums[r]);
                cur_sum += nums[r];
                ++r;
            }
            res = max(res, cur_sum);
        }
        return res;
    }
};
