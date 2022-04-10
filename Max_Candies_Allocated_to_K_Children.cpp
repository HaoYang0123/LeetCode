// Leetcode 2226

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long left = 1, right = 0;
        for(int i=0; i<candies.size(); ++i) right = max(right, (long long)(candies[i]));
        long long res = 0;
        while(left <= right) {
            long long mid = left + (right - left) / 2;
            long long tmp = 0;
            for(int i=0; i<candies.size(); ++i) {
                tmp += candies[i] / mid;
                if(tmp >= k) break;
            }
            if(tmp >= k) {
                res = max(res, mid);
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        return res;
    }
};
