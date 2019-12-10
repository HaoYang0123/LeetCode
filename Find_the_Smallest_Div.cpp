//Leetcode 1283
//O(NlogSum)的时间复杂度

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long start=1, end=0, res = INT_MAX;
        for(int i=0;i<nums.size();++i) end += (long long)nums[i];
        while(start<=end) {
            long long mid = start + (end-start)/2;
            long long div_res = get_res(nums, mid);
            if(div_res <= threshold) {
                res = min(res, mid);
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return res;
    }
    
    long long get_res(vector<int> & nums, int div) {
        long long res = 0;
        for(int i=0;i<nums.size();++i) {
            res += ((long long)nums[i]-1) / div + 1;
        }
        return res;
    }
};
