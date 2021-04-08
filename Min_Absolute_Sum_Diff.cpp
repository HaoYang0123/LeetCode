// Leetcode 1818

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        set<int> s(begin(nums1), end(nums1));
        long res = 0, gain = 0;
        for(int i=0;i<nums1.size();++i) {
            long curDiff = (long)(abs(nums1[i] - nums2[i]));
            res += curDiff;
            auto ind = s.lower_bound(nums2[i]);
            if(ind != end(s)) gain = max(gain, curDiff - abs(nums2[i] - *ind));
            if(ind != begin(s)) gain = max(gain, curDiff - abs(nums2[i] - *prev(ind)));
        }
        return (res - gain) % 1000000007;
    }
};
