// Leetcode 2262

class Solution {
public:
    long long appealSum(string s) {
        long long res = 0;
        unordered_map<char, vector<int>> c2pos;
        for(int i=0; i<s.length(); ++i) {
            c2pos[s[i]].push_back(i);
        }
        for(int i=0; i<s.length(); ++i) {
            char c = s[i];
            vector<int> & pos = c2pos[c];
            auto idx = upper_bound(pos.begin(), pos.end(), i);
            int next_pos = s.length();
            if(idx != pos.end()) next_pos = *idx;
            long long tmp = (long long)(i+1) * (next_pos - i);
            res += tmp;
        }
        return res;
    }
};
