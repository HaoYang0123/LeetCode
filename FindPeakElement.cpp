//一个数组，找a[i]>a[i-1]&&a[i]>a[i+1]，即元素比两边邻居都大的元素位置

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0, end = nums.size() - 1, mid = 0, mid2 = 0;
        while(start < end) {
            mid = start + (end - start) / 2;
            mid2 = mid + 1;
            if(nums[mid] < nums[mid2]) start = mid2;
            else end = mid;
        }
        return start;
    }
};
