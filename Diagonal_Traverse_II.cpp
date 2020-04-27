//Leetcode 1424

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        map<int, vector<int>> mm;
        for(int i=0;i<nums.size();++i) {
            vector<int> & row = nums[i];
            for(int j=0;j<row.size();++j) {
                int k = i+j;
                mm[k].push_back(row[j]);
            }
        }
        for(auto ind = mm.begin(); ind != mm.end(); ++ind) {
            vector<int> & diagonal = ind->second;
            for(int i = diagonal.size()-1; i >= 0; --i) {
                res.push_back(diagonal[i]);
            }
        }
        return res;
    }
};
