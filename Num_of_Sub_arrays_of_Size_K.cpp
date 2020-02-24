//Leetcode 1343

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0;
        int cur_sum = 0;
        for(int i=0; i<k; ++i) cur_sum += arr[i];
        int t = k * threshold;
        if(cur_sum >= t) ++res;
        for(int i=k;i<arr.size();++i) {
            cur_sum += (arr[i] - arr[i-k]);
            if(cur_sum >= t) ++res;
        }
        return res;
    }
};
