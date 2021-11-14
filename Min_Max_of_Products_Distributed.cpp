// Leetcode 2064

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int min_v = 1, max_v = INT_MIN;
        for(int i=0; i<quantities.size(); ++i) {
            max_v = max(max_v, quantities[i]);
        }
        int res = max_v;
        while(min_v <= max_v) {
            int mid = (min_v + max_v) / 2;
            if(is_valid(quantities, n, mid)) {
                res = min(res, mid);
                max_v = mid-1;
            }
            else {
                min_v = mid+1;
            }
        }
        return res;
    }
    
    inline bool is_valid(vector<int> & quantities, int n, int mid) {
        int need_num = 0;
        for(int i=0; i<quantities.size(); ++i) {
            if(quantities[i] % mid == 0) need_num += quantities[i] / mid;
            else need_num += (quantities[i] / mid + 1);
        }
        return need_num <= n;
    }
};
