//Leetcode 812

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res = 0.0;
        for(int i=0;i<points.size();++i) {
            for(int j=i+1;j<points.size();++j) {
                for(int k=j+1;k<points.size();++k) {
                    double tmp = solver(points[i], points[j], points[k]);
                    res = max(res, tmp);
                }
            }
        }
        return res;
    }
    
    double solver(vector<int> &p1,vector<int> & p2,vector<int> & p3)
    {
        pair<int,int> retv;
        double x0 = p1[0];
        double y0 = p1[1];

        double x1 = p2[0];
        double y1 = p2[1];

        double x2 = p3[0];
        double y2 = p3[1];
        if(x0-x1 != 0)
        {
            double k  = (y0-y1)/(x0-x1);
            double b = y1-k*x1;
            //y=kx+b   kx-y+b = 0   
            double high = abs(k*x2-y2+b)/sqrt(1+k*k);
            double longth = sqrt((x1-x0)*(x1-x0)+(y1-y0)*(y1-y0));
            return high *longth*0.5;   
        }
            // x = constant
        return abs(y1-y0)*abs(x1-x2)*0.5;
    }
};
