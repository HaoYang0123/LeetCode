//Leetcode 1401

class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        if(x_center >= x1 && x_center <= x2 && y_center >= y1 && y_center <= y2) return true; //在矩形内
        if(x_center < x1 && y_center >= y1 && y_center <= y2) { //左方
            int dis = x1 - x_center;
            if(dis <= radius) return true;
            return false;
        }
        if(x_center < x1 && y_center > y2) { //左上方
            double dis = get_dis(x_center, y_center, x1, y2);
            if(dis <= radius) return true;
            return false;
        }
        if(x_center < x1 && y_center < y1) { //左下方
            double dis = get_dis(x_center, y_center, x1, y1);
            if(dis <= radius) return true;
            return false;
        }
        if(x_center >= x1 && x_center <= x2 && y_center > y2) { //上方
            int dis = y_center - y2;
            if(dis <= radius) return true;
            return false;
        }
        if(x_center >= x1 && x_center <= x2 && y_center < y1) { //下方
            int dis = y1 - y_center;
            if(dis <= radius) return true;
            return false;
        }
        if(x_center > x2 && y_center >= y1 && y_center <= y2) { //右方
            int dis = x_center - x2;
            if(dis <= radius) return true;
            return false;
        }
        if(x_center > x2 && y_center > y2) { //右上方
            int dis = get_dis(x_center, y_center, x2, y2);
            if(dis <= radius) return true;
            return false;
        }
        if(x_center > x2 && y_center < y1) { //右下方
            int dis = get_dis(x_center, y_center, x2, y1);
            if(dis <= radius) return true;
            return false;
        }
        return false;
    }
    
    inline double get_dis(int x1, int y1, int x2, int y2) {
        return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    }
};
