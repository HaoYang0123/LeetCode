//Leetcode 1465

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long max_h = 0, max_w = 0;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        for(int i = 0; i < horizontalCuts.size(); ++i) {
            long long cur_h = 0;
            if(i == 0) cur_h = horizontalCuts[i];
            else cur_h = horizontalCuts[i] - horizontalCuts[i-1];
            max_h = max(max_h, cur_h);
        }
        max_h = max(max_h, (long long)h - horizontalCuts.back());
        for(int i = 0; i < verticalCuts.size(); ++i) {
            long long cur_w = 0;
            if(i == 0) cur_w = verticalCuts[i];
            else cur_w = verticalCuts[i] - verticalCuts[i-1];
            max_w = max(max_w, cur_w);
        }
        max_w = max(max_w, (long long)w - verticalCuts.back());
        return (long long)(max_h * max_w) % 1000000007;
    }
};
