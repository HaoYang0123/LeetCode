// Leetcode 1865

class FindSumPairs {
public:
    vector<int> nums2;
    unordered_map<int,int> v2n1, v2n;  //nums2中value对应的数量（为何是nums2，而不是nums1，因为nums2的数量是10^5，而nums1只有10^3）
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums2 = nums2;
        for(int i=0; i<nums2.size(); ++i) v2n[nums2[i]]++;
        for(int i=0; i<nums1.size(); ++i) v2n1[nums1[i]]++;
    }
    
    void add(int index, int val) {
        int cur_v = nums2[index];
        v2n[cur_v]--;
        if(v2n[cur_v] == 0) v2n.erase(v2n.find(cur_v));
        v2n[cur_v+val]++;
        nums2[index] = cur_v+val;
    }
    
    int count(int tot) {
        int res = 0;
        for(auto idx=v2n1.begin(); idx!=v2n1.end(); ++idx) {
            int c = tot - idx->first;
            res += idx->second * v2n[c];
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
