//在有重复数字的有序列但在某个位置发生反转的数组下找最小元素；
//比如数组：2,2,1,2,2

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1, mid = 0;
        while(start < end) {
            mid = start + (end - start) / 2;
            if(nums[mid] > nums[end]) start = mid + 1;
            else if(nums[mid] < nums[end]) end = mid;
            else --end;
        }
        return nums[start];
    }
};
