// Leetcode 1779

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int res = -1, min_dis = INT_MAX;
        for(int i = 0; i < points.size(); ++i) {
            if(points[i][0] != x && points[i][1] != y) continue;
            int cur_dis = abs(points[i][0] - x) + abs(points[i][1] - y);
            if(cur_dis < min_dis) {
                res = i;
                min_dis = cur_dis;
            }
        }
        return res;
    }
};
