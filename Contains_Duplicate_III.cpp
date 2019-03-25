//Leetcode 220
//O(N*LogK)的时间复杂度，从网上找的代码。
//试了一下，下面的代码会出现加、减法溢出的问题，所以需要将int强制转化为long long，如第二套代码。

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<int> window; // set is ordered automatically 
    for (int i = 0; i < nums.size(); i++) {
        if (i > k) window.erase(nums[i-k-1]); // keep the set contains nums i j at most k
        // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
        auto pos = window.lower_bound(nums[i] - t); // x-nums[i] >= -t ==> x >= nums[i]-t 
        // x - nums[i] <= t ==> |x - nums[i]| <= t    
        if (pos != window.end() && *pos - nums[i] <= t) return true;
        window.insert(nums[i]);
    }
    return false;
}

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        t = (long long)t;
        set<long long> ss; //保存最近K+1个元素
        for(int i=0;i<nums.size();++i) {
            if(i>k) ss.erase((long long)nums[i-k-1]);
            auto ind=ss.lower_bound((long long)nums[i]-t); //在ss中找到>=nums[i]-t的元素
            if(ind != ss.end() && (*ind)-t <= (long long)nums[i]) return true; //如果找到了，且该元素<=nums[i]+t，说明ind与nums[i]是答案
            ss.insert((long long)nums[i]);
        }
        return false;
    }
};
