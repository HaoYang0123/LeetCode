//Leetcode 239

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> win;
        int n=nums.size();
        if(n==0) return vector<int>();
        int cur_max = INT_MIN;
        for(int i=0;i<k;++i) {
            win[nums[i]]++;
            cur_max = max(cur_max, nums[i]);
        }
        vector<int> res(n-k+1, 0);
        res[0] = cur_max;
        for(int i=k;i<n;++i) {
            win[nums[i-k]]--;
            win[nums[i]]++;
            auto ind = win.rbegin();
            while(ind != win.rend() && ind->second == 0) {
                ++ind;
            }
            res[i+1-k] = ind->first;
        }
        return res;
    }
};
