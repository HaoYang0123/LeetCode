// Leetcode 1725

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        map<int,int> maxLen2num;
        for(int i=0; i<rectangles.size(); ++i) {
            int m = min(rectangles[i][0], rectangles[i][1]);
            //cout<<i<<'\t'<<m<<endl;
            maxLen2num[m]++;
        }
        auto ind = maxLen2num.end();
        --ind;
        return ind->second;
    }
};
