//Leetcode 1329

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));
        map<int, vector<int>> ind2vals;
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                int ind = (n-i)+j;
                ind2vals[ind].push_back(mat[i][j]);
            }
        }
        for(auto ind = ind2vals.begin(); ind != ind2vals.end(); ++ind) {
            vector<int> & vals = ind->second;
            sort(vals.begin(), vals.end());
            int indv = ind->first;
            int i = indv - n;
            if(i <= 0) {
                i = -i;
                int j = 0;
                for(int k = 0; k < vals.size(); ++k) res[i+k][j+k] = vals[k];
            }
            else {
                int j = i;
                i = 0;
                for(int k = 0; k < vals.size(); ++k) res[i+k][j+k] = vals[k];
            }
        }
        return res;
    }
};
