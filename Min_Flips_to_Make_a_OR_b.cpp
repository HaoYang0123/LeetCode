//Leetcode 1318

class Solution {
public:
    int minFlips(int a, int b, int c) {
        vector<int> a_bit = get_bits(a);
        vector<int> b_bit = get_bits(b);
        vector<int> c_bit = get_bits(c);
        int res = 0;
        int n = max(a_bit.size(), max(b_bit.size(), c_bit.size()));
        for(int i=0;i<n;++i) {
            int a_b = (i >= a_bit.size() ? 0 : a_bit[i]);
            int b_b = (i >= b_bit.size() ? 0 : b_bit[i]);
            int c_b = (i >= c_bit.size() ? 0 : c_bit[i]);
            if(c_b == 0) {
                res += (a_b + b_b); //a_b和b_b为1的个数，如果两个都为1，则需要将两个都反转为0
            }
            else {
                if(a_b == 0 && b_b == 0) res++; //只要不是两个都为0，则不用反转
            }
        }
        return res;
    }
    
    inline vector<int> get_bits(int a) {
        vector<int> res;
        while(a > 0) {
            res.push_back(a%2);
            a/=2;
        }
        return res;
    }
};
