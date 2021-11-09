// Leetcode 912
//快速排序


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size()-1);
        return nums;
    }
    
    void quicksort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return;
        int l = left, r = right;
        int index = rand()%(right-left+1)+left; //随机从[left,right]之间选择一个数与left值交换，这样的pivot是随机选择的值，不然会超时
        swap(nums[left],nums[index]);
        int pivot = nums[left];
        while (l < r) {
            while (l < r && nums[r] >= pivot) r--;
            while (l < r && nums[l] <= pivot) l++;
            if (l < r)
                swap(nums[l], nums[r]);
        }
        // l==r
        nums[left] = nums[l];
        nums[l] = pivot;
        quicksort(nums, left, l-1);
        quicksort(nums, l+1, right);
    }
};
