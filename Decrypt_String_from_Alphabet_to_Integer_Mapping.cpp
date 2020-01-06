//Leetcode 1309

class Solution {
public:
    string freqAlphabets(string s) {
        string res = "";
        for(int i=0;i<s.length();++i) {
            if(i+2 < s.length() && s[i+2] == '#') {
                int index = atoi(s.substr(i,2).c_str());
                res += (char)('a'+index-1);
                i += 2;
            }
            else res += (char)('a' + atoi(s.substr(i,1).c_str()) - 1);
        }
        return res;
    }
};
