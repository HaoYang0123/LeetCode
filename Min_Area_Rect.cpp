//Leetcode 939
//剪枝+Hash索引

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, vector<int>> mm;
        int n = points.size();
        for(int i=0;i<n;++i) {
            mm[points[i][0]].push_back(points[i][1]);
        }
        int res = INT_MAX;
        for(auto ind1 = mm.begin();ind1 != mm.end(); ++ind1) {
            if(ind1->second.size() <= 1) continue;
            for(auto ind2 = mm.begin();ind2 != mm.end();++ind2) {
                if(ind2->second.size() <= 1) continue;
                if(ind1->first >= ind2->first) continue;
                if(ind2->first - ind1->first >= res) continue;
                int tmp = find_val(ind1->second, ind2->second);
                if(tmp == INT_MAX) continue;
                int cur = (ind2->first-ind1->first) * tmp;
                if(cur < res) res = cur;
            }
        }
        if(res == INT_MAX) return 0;
        return res;
    }
    
    int find_val(vector<int> & v1, vector<int> & v2) {
        vector<int> yes;
        unordered_map<int, bool> mm;
        for(int i=0;i<v1.size();++i) mm[v1[i]] = true;
        for(int i=0;i<v2.size();++i) {
            if(mm.find(v2[i]) != mm.end()) {
                yes.push_back(v2[i]);
            }
        }
        if(yes.size() <= 1) return INT_MAX;
        sort(yes.begin(), yes.end());
        int res = INT_MAX;
        for(int i=1;i<yes.size();++i) {
            if(yes[i]-yes[i-1] < res) res = yes[i]-yes[i-1];
        }
        return res;
    }
};
