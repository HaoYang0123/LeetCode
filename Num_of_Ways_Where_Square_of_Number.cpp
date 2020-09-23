//Leetcode 1577

class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<long long, int> n1, n2;
        for(int i=0;i<nums1.size();++i) {
            n1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();++i) {
            n2[nums2[i]]++;
        }
        int res = 0;
        for(int i=0;i<nums1.size();++i) {
            for(int j=i+1;j<nums1.size();++j) {
                long long t = (long long)nums1[i] * nums1[j];
                long long t2 = sqrt(t);
                if(t2 * t2 == t) {
                    auto ind = n2.find(t2);
                    if(ind != n2.end()) res += ind->second;
                }
            }
        }
        for(int i=0;i<nums2.size();++i) {
            for(int j=i+1;j<nums2.size();++j) {
                long long t = (long long)nums2[i] * nums2[j];
                long long t2 = sqrt(t);
                if(t2 * t2 == t) {
                    auto ind = n1.find(t2);
                    if(ind != n1.end()) res += ind->second;
                }
            }
        }
        return res;
    }
};
