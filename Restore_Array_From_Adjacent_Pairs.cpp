// Leetcode 1743

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> mm;
        int n = adjacentPairs.size();
        for(int i=0;i<adjacentPairs.size();++i) {
            mm[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            mm[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }
        vector<int> res(n+1, 0);
        for(auto ind = mm.begin(); ind != mm.end(); ++ind) {
            if(ind->second.size() == 1) { //找到出度为1的，就是原数组中第1个元素
                res[0] = ind->first;
                break;
            }
        }
        for(int i = 1; i <= n; ++i) {
            vector<int> & edges = mm[res[i-1]];
            if (edges.size() == 1) res[i] = edges[0];
            else {
                for(int j=0;j<edges.size(); ++j) {//edges数量只能是1和2
                    if(edges[j] != res[i-2]) { //这里for循环中edges数量一定是2，这两个数其中一个已经连接放入res[i-2]中，另外一个则是当前需要的res[i]
                        res[i] = edges[j];
                        break;
                    }
                }
            }
        }
        return res;
    }
};
