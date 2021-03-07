// Leetcode 1775

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int min1 = nums1.size(), max1 = 6 * nums1.size();
        int min2 = nums2.size(), max2 = 6 * nums2.size();
        if(min1 > max2 || max1 < min2) return -1;
        int sum1 = get_sum(nums1), sum2 = get_sum(nums2);
        if(sum1 == sum2) return 0;
        if(sum1 < sum2) swap(nums1, nums2); //维持nums1数组和比nums2大
        int diff = abs(sum1 - sum2);
        unordered_map<int,int> mm;
        for(int i=0; i<nums1.size(); ++i) mm[nums1[i]-1]++;
        for(int i=0; i<nums2.size(); ++i) mm[6-nums2[i]]++;
        int j = 5, res = 0;
        while(diff > 0 && j > 0) {
            int ops = min(mm[j], int((diff - 1) / j) + 1); //如果diff=11，j=5，那么最好能够操作2个J的值，这样diff下降更快
            res += ops;
            diff -= ops * j;
            --j;
        }
        return res;
    }
    
    inline int get_sum(vector<int> & nums) {
        int res = 0;
        for(int i=0; i<nums.size(); ++i) res += nums[i];
        return res;
    }
};
