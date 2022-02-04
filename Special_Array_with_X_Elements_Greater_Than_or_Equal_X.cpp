// Leetcode 1608

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start = 0, end = 1000;
        while(start<=end) {
            int mid = (start+end) / 2;
            int idx = lower_bound(nums.begin(), nums.end(), mid) - nums.begin();
            int count = nums.size() - idx;
            //cout<<mid<<"\t"<<idx<<"\t"<<count<<endl;
            //cout<<start<<":"<<end<<endl;
            if(mid == count) return mid;
            else if(mid > count) end = mid-1;
            else start = mid+1;
        }
        return -1;
    }
};
