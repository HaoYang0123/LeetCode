//Leetcode 1351

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        for(int i=0;i<grid.size();++i) {
            res += get_neg_num(grid[i]);
        }
        return res;
    }
    
    inline int get_neg_num(vector<int> & row) {
        int mid = -1;
        int start = 0, end = row.size()-1;
        while(start<=end) {
            mid = (start+end)/2;
            if(row[mid] >= 0) start = mid+1;
            else end=mid-1;
        }
        //cout<<start<<endl;
        return row.size()-start;
    }
};
