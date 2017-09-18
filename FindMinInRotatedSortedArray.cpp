//在一个排序但在某个位置反转的数组中找最小值
//比如，数组：4,5,6,7,0,1,2

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while(start < end) {
            if(nums[start] < nums[end]) return nums[start];
            int mid = (start + end) >> 1;
            if(nums[mid] > nums[end]) start = mid + 1;
            else end = mid;
        }
        return nums[start];
    }
}
