//Leetcode 1337

bool cmp(const pair<int,int> & a, const pair<int,int> & b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> vs;
        for(int i=0;i<mat.size();++i) {
            vs.push_back(pair<int,int>(get_soldier_num(mat[i]), i));
        }
        sort(vs.begin(), vs.end(), cmp);
        vector<int> res;
        for(int i=0;i<k;++i) res.push_back(vs[i].second);
        return res;
    }
    
    inline int get_soldier_num(vector<int> & row) {
        int num = 0;
        for(int i=0;i<row.size();++i) {
            if(row[i] == 0) break;
            ++num;
        }
        return num;
    }
};
