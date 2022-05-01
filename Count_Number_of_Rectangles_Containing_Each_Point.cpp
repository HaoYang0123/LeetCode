// Leetcode 2250

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> yy_rec(102, vector<int>());   //yy_rec[i]表示y坐标大于等于i的rectangles中的x的所有坐标
        for(int i=0; i<rectangles.size(); ++i) {
            int y = rectangles[i][1];
            yy_rec[y].push_back(rectangles[i][0]);
        }
        for(int i=yy_rec.size()-2; i>=0; --i) {
            yy_rec[i].insert(yy_rec[i].end(), yy_rec[i+1].begin(), yy_rec[i+1].end());
        }
        int n = points.size();
        vector<int> res(n, 0);
        vector<vector<int>> yy_points(102, vector<int>());  //yy_points[i]表示y坐标等于i的points中的所有坐标
        map<pair<int,int>, int> point2idx;
        for(int i=0; i<n; ++i) {
            int x = points[i][0], y = points[i][1];
            point2idx[{x, y}] = i;
            yy_points[y].push_back(x);
        }
        //cout<<"OK"<<endl;
        for(int i=0; i<yy_points.size(); ++i) {
            vector<int> & cur_point = yy_points[i];
            if(cur_point.size() == 0) continue;  //无points
            vector<int> & cur_rec = yy_rec[i];
            sort(cur_point.begin(), cur_point.end());   //两个x坐标数组，均需要从小到大排序
            sort(cur_rec.begin(), cur_rec.end());
            int j = cur_point.size()-1, k = cur_rec.size()-1;
            int tmp = 0;
            while(j>=0 && k>=0) {
                int cur_x = cur_point[j];
                int cur_c = cur_rec[k];
                if(cur_c >= cur_x) {
                    ++tmp;
                    --k;
                }
                else {  //当前cur_x位置下，有多少个cur_rec是大于等于cur_x的，则说明是有多少矩阵是包含此点的，因为cur_rec中的y坐标是全部大于等于当前y(这里的i)
                    int point_idx = point2idx[{cur_x, i}];
                    res[point_idx] = tmp;
                    --j;
                }
            }
            while(j>=0) {
                int cur_x = cur_point[j];
                int point_idx = point2idx[{cur_x, i}];
                res[point_idx] = tmp;
                --j;
            }
        }
        return res;
    }
};
