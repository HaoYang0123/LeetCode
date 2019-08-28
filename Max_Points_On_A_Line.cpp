//Leetcode 149

class Solution {
public:
    pair<int,int> get_angle(vector<int> & a, vector<int> & b) {
        int dx = a[0]-b[0];
        int dy = a[1]-b[1];
        if(dx != 0 && dy != 0) {
            int gcd_v = __gcd(abs(dx), abs(dy));
            return pair<int,int>(dx/gcd_v, dy/gcd_v);
        }
        return pair<int,int>(!(dx==0), !(dy==0));
    }
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==0) return 0;
        int res=1;
        sort(points.begin(), points.end()); //一定的排序，比如(1,1),(0,0),(2,2)本来是共线的
        //如果不排序(1,1)为基点，那么会导致(0,0)与(2,2)算出来的斜率不一样(分别是(1,1)和(-1,-1))
        //sort不仅得考虑上面的问题，还得考虑相同点的情况，比如(0,0),(1,1),(0,0)
        //如果不sort，那么cur=1（后面才是=2），但在计算(1,1)时就已经将mm更新了
        //所以先sort后，两个(0,0)在(1,1)前面，cur=2，当计算(1,1)时cur已经是2了
        for(int i=0;i<points.size()-1;++i) {
            int cur=1; //points[i]的数量
            map<pair<int,int>, int> mm;
            for(int j=i+1;j<points.size();++j) {
                if(points[i]==points[j]) {
                    ++cur; //如果j与i的坐标相同，则cur++
                    res = max(res, cur);
                }
                else {
                    pair<int,int> ll = get_angle(points[i], points[j]);
                    mm[ll]++; //mm表示以i为基点，斜率相同的其余点的数量
                    res = max(res, mm[ll] + cur);
                }
            }
        }
        return res;
    }
};
