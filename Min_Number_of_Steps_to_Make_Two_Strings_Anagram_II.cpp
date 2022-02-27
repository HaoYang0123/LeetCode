// Leetcode 2186

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> sm = get_map(s);
        unordered_map<char, int> tm = get_map(t);
        int res = 0;
        for(auto idx = sm.begin(); idx != sm.end(); ++idx) {
            int t1 = idx->second;
            int t2 = tm[idx->first];
            res += abs(t1 - t2);
        }
        for(auto idx = tm.begin(); idx != tm.end(); ++idx) {
            if(sm.find(idx->first) != sm.end()) continue;
            res += idx->second;
        }
        return res;
    }
    
    inline unordered_map<char, int> get_map(string & s) {
        unordered_map<char, int> res;
        for(int i=0; i<s.length(); ++i) res[s[i]]++;
        return res;
    }
};
