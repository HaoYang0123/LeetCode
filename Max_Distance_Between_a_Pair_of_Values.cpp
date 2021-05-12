// Leetcode 1855

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        for(int i=0; i<nums2.size(); ++i) nums2[i] = -nums2[i];  //转成负数，就相当于是从小到大排序了
        for(int i=0; i<nums1.size(); ++i) {
            int v = -nums1[i];
            auto ind = upper_bound(nums2.begin(), nums2.end(), v);  //由于已经转成负数了，所以这里找到nums2中第1个比v要大的数
            if(ind == nums2.begin()) continue;
            --ind;  //--ind，那么就相当于是nums2中最后一个要小于等于v的数
            int j = ind - nums2.begin();
            res = max(res, j - i);
        }
        return res;
    }
};
