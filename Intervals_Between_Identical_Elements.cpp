// Leetcode 2121

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<int>> v2pos;
        for(int i=0; i<arr.size(); ++i) v2pos[arr[i]].push_back(i);
        vector<long long> res(arr.size(), 0);
        for(auto idx = v2pos.begin(); idx != v2pos.end(); ++idx) {
            vector<int> & pos = idx->second;
            long long cur_c = 0;
            for(int i=1; i<pos.size(); ++i) cur_c += (long long)(pos[i]-pos[0]);
            res[pos[0]] = cur_c;
            int x = pos.size()-1, y=1;
            for(int i=1; i<pos.size(); ++i) {
                res[pos[i]] = res[pos[i-1]] + (y-x)*(pos[i]-pos[i-1]);
                --x;
                ++y;
            }
        }
        return res;
    }
};
