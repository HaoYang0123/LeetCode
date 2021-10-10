// Leetcode 2022

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int ori_num = original.size();
        if(ori_num != m * n) return vector<vector<int>>();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for(int i=0; i<ori_num; ++i) {
            int newi = i / n;
            int newj = i % n;
            res[newi][newj] = original[i];
        }
        return res;
    }
};
