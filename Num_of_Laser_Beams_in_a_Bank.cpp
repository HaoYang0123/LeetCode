// Leetcode 2125

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0;
        int old = 0;
        for(int i=0; i<bank.size(); ++i) {
            int cur = get_device_num(bank[i]);
            if(cur != 0) {
                res += (old * cur);
                old = cur;
            }
        }
        return res;
    }
    
    inline int get_device_num(string & one_row) {
        int res = 0;
        for(int i=0; i<one_row.length(); ++i) {
            if(one_row[i] == '1') ++res;
        }
        return res;
    }
};
