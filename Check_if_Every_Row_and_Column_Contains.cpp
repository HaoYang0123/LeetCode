// Leetcode 2133

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size(); ++i) {
            unordered_set<int> ss;
            for(int j=0; j<matrix[0].size(); ++j) {
                if(ss.find(matrix[i][j]) != ss.end()) return false;
                ss.insert(matrix[i][j]);
            }
        }
        for(int i=0; i<matrix[0].size(); ++i) {
            unordered_set<int> ss;
            for(int j=0; j<matrix.size(); ++j) {
                if(ss.find(matrix[j][i]) != ss.end()) return false;
                ss.insert(matrix[j][i]);
            }
        }
        return true;
    }
};
