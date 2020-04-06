//Leetcode 1395
//O(N^2)时间复杂度
//有个O(NlogN)时间复杂度方法，使用的tree index array

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int res = 0;
        for(int i=0;i<n;++i) {
            int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
            for(int j=0;j<i;++j) {
                if(rating[j]>rating[i]) ++x1;
                else if(rating[j]<rating[i]) ++x2;
            }
            for(int j=i+1;j<n;++j) {
                if(rating[j]>rating[i]) ++y1;
                else if(rating[j]<rating[i]) ++y2;
            }
            res += (x1*y2 + x2*y1);
        }
        return res;
    }
};
