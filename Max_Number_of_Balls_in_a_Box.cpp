// Leetcode 1742

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> box2num; // box2num[i]表示第i个box的球的数量
        int res = 0;
        for(int i=lowLimit; i<=highLimit; ++i) {
            int bind = get_box_index(i);
            box2num[bind]++;
            res = max(res, box2num[bind]);
        }
        return res;
    }
    
    inline int get_box_index(int v) {
        int res = 0;
        while(v>0) {
            res += v % 10;
            v /= 10;
        }
        return res;
    }
};
