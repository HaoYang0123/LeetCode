//Leetcode 164
//问题：一个未排序的数组，计算排序后两个连续数的最大差
//如果是O(nlogn)的时间复杂度，可以先排序再做
//如果是O(n)的时间复杂度，那么需要进行桶排序。将数组中最大值减最小值，除以间隔数（间隔数等于数组元素-1），最大间隔应该比该值大
//所以可以按此间隔对数组中元素分桶，桶中只记录落在桶中的最小值和最大值，这样最大的间隔只能发生连续桶中（等于下一个桶中最小值减当前桶中最大值）
//不用考虑当前桶的最大值减最小值，因为上面已经解释

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int min_val = INT_MAX, max_val = INT_MIN;
        if(nums.size()<=1) return 0;
        int n = nums.size();
        for(int i=0;i<n;++i) {
            if(nums[i]>max_val) max_val = nums[i];
            if(nums[i]<min_val) min_val = nums[i];
        }
        if(max_val == min_val) return 0; //防止gap=0，导致后面的除0错误
        double gap = (max_val - min_val) * 1.0 / (n-1);
        vector<int> min_bin(n, INT_MAX);
        vector<int> max_bin(n, INT_MIN);
        for(int i=0;i<n;++i) {
            int bin_index = (int)((nums[i]-min_val) / gap);
            if(min_bin[bin_index] > nums[i]) min_bin[bin_index] = nums[i];
            if(max_bin[bin_index] < nums[i]) max_bin[bin_index] = nums[i];
        }
        int res = 0;
        int cur_max = max_bin[0];
        for(int i=1;i<n;++i) {
            if(min_bin[i] == INT_MAX) continue;
            int cur_res = min_bin[i] - cur_max;
            cur_max = max_bin[i];
            if(cur_res > res) res = cur_res;
        }
        return res;
    }
};
