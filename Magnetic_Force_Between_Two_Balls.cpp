// Leetcode 1552
// 二分查找，答案一定在[1, INT_MAX]中产生，二分去查找此mid值是否可以将m个球放入各position中

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n=position.size();
        int start=1;
        int len = position[n-1] - position[0];
        int end = (len-1-(m-2)) / (m-1)+1;
        int res = 0;
        while(start<=end) {
            int mid=start + (end-start)/2;
            if(check_ok(position, mid, m)) {
                res = max(res, mid);
                start = mid+1;
            }
            else end = mid-1;
        }
        return res;
    }
    
    inline bool check_ok(vector<int> & position, int mid, int m) {
        int cur = 0;
        for(int i=0; i<m; ++i) {
            auto idx = lower_bound(position.begin(), position.end(), cur);  //找到第1个>=cur的位置，将第i个球放进去，总共需要放m个球，才算成功，但每个球的间隔得超过mid
            if(idx == position.end()) return false;
            int cur_pos = *idx;
            cur = cur_pos + mid;  //下一个球的位置一定得>=cur_pos+mid
        }
        return true;
    }
};
