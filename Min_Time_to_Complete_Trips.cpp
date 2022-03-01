// Leetcode 2187
//二分查找

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long max_t = 0;
        for(int i=0; i<time.size(); ++i) {
            max_t = max(max_t, (long long)(time[i]));
        }
        long long left = 1, right = max_t * totalTrips;
        while(left<right) {  //在[left,right]区间的均是答案
            long long mid = (left+right)/2;
            long long cur = 0;
            bool is_big = false;
            for(int i=0; i<time.size(); ++i) {
                cur += (mid / time[i]);
                if(cur >= totalTrips) {
                    is_big = true;
                    break;
                }
            }
            if(is_big) right = mid;
            else left = mid+1;
        }
        return left;
    }
};
