//Leetcode 1323

class Solution {
public:
    int maximum69Number (int num) {
        vector<int> bts = get_bit(num);
        int res = 0;
        bool is_reversed = false;
        int bit_num = bts.size();
        int b_multi = 1;
        while(--bit_num) b_multi *= 10;
        //cout<<b_multi<<endl;
        for(int i=bts.size()-1;i>=0;--i) {
            if(!is_reversed && bts[i] == 6) {
                is_reversed = true;
                res += b_multi * 9;
            }
            else {
                res += b_multi * bts[i];
            }
            b_multi /= 10;
        }
        return res;
    }
    
    vector<int> get_bit(int n) {
        vector<int> res;
        while(n > 0) {
            int b = n % 10;
            res.push_back(b);
            n /= 10;
        }
        return res;
    }
};
