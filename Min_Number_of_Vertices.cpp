//Leetcode 1557
//找到所有入度为0的结点，即为答案

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> m2ind;
        for(int i=0;i<edges.size();++i) {
            m2ind.insert(edges[i][1]);
        }
        vector<int> res;
        for(int i=0;i<n;++i) {
            if(m2ind.find(i) == m2ind.end()) res.push_back(i);
        }
        return res;
    }
};
