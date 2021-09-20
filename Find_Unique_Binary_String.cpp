// Leetcode 1980

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> ss;
        for(auto v : nums) ss.insert(v);
        string cur = "";
        for(int i=0; i<nums.size(); ++i) cur += "0";
        while(ss.find(cur) != ss.end()) {
            get_next(cur);
        }
        return cur;
    }
    
    inline void get_next(string & cur) {
        int bit = 1;
        for(int i=cur.length()-1; i>=0; --i) {
            int newc = int(cur[i] - '0') + bit;
            cur[i] = char(newc % 2) + '0';
            bit = newc / 2;
            if(bit == 0) return ; 
        }
    }
};
