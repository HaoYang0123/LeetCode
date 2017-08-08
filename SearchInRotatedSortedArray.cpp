class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size() - 1);
    }
    
    bool search(vector<int> & nums, int target, int start, int end) {
        int mid = 0;
        if(start > end) return false;
        while(start <= end) {
            mid = (start + end) >> 1;
            if(nums[mid] == target) return true;
            if(nums[start] < nums[mid]) {
                if(nums[start] <= target && target <= nums[mid]) {
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
            else if(nums[mid] < nums[end]) {
                if(nums[mid] <= target && target <= nums[end]) {
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
            else {
                return search(nums, target, mid + 1, end) || search(nums, target, start, mid - 1);
            }
        }
        return false;
    }
};
