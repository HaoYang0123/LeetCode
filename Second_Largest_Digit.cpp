// Leetcode 1796

class Solution {
public:
    int secondHighest(string s) {
        set<int> dig;
        vector<int> dig_v;
        for(int i=0;i<s.length();++i) {
            if(s[i] >= '0' && s[i] <= '9') {
                int c = (int)(s[i]-'0');
                if(dig.find(c) == dig.end()) {
                    dig.insert(c);
                    dig_v.push_back(c);
                }
            }
        }
        if(dig.size() <= 1) return -1;
        sort(dig_v.begin(), dig_v.end());
        return dig_v[dig_v.size()-2];
    }
};
