// Leetcode 2259

class Solution {
public:
    string removeDigit(string number, char digit) {
        vector<int> pos;
        for(int i=0; i<number.length(); ++i) {
            if(number[i] == digit) pos.push_back(i);
        }
        string max_str = "";
        for(int i=0; i<pos.size(); ++i) {
            string tmp = number.substr(0, pos[i]) + number.substr(pos[i]+1);
            if(max_str == "") max_str = tmp;
            else if(max_str < tmp) max_str = tmp;
        }
        return max_str;
    }
};
