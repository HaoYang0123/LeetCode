// Leetcode 2103

class Solution {
public:
    int countPoints(string rings) {
        unordered_map<int, string> pos2str;
        for(int i=0; i<rings.length(); i += 2) {
            char c = rings[i];
            int idx = int(rings[i+1] - '0');
            pos2str[idx] += c;
        }
        int res = 0;
        for(auto idx = pos2str.begin(); idx != pos2str.end(); ++idx) {
            string & str = idx->second;
            int r = 0, g = 0, b = 0;
            for(int i=0; i<str.length(); ++i) {
                if(str[i] == 'R') ++r;
                else if(str[i] == 'G') ++g;
                else ++b;
            }
            if(r > 0 && g > 0 && b > 0) ++res;
        }
        return res;
    }
};
