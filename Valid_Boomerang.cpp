//Leetcode 1037

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int delta_x = points[0][0]-points[1][0];
        int delta_y = points[0][1]-points[1][1];
        int delta_x2 = points[0][0]-points[2][0];
        int delta_y2 = points[0][1]-points[2][1];
        if(delta_x==0 && delta_y==0) return false;
        if(delta_x2==0 && delta_y2==0) return false;
        if(points[1][0]==points[2][0] && points[1][1]==points[2][1]) return false;
        if(delta_x*delta_y2==delta_x2*delta_y) return false;
        return true;
    }
};
