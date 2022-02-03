// Leetcode 1901
//二分查找，用两分的方式找到某一行中最大的元素均比上一行和下一行的最大元素都大

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        int l=0, r=m-1;
        while(l<r) {
            int mid=(l+r)/2;
            int max1 = *max_element(mat[mid].begin(), mat[mid].end());
            int max2 = *max_element(mat[mid+1].begin(), mat[mid+1].end());
            if(max1<max2) l=mid+1;
            else r=mid;
        }
        vector<int> res;
        int max_c = -1;
        for(int i=0; i<n; ++i) {
            if(mat[l][i] > max_c) {
                max_c = mat[l][i];
                res = {l, i};
            }
        }
        return res;
    }
};
