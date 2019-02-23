//Leetcode 869

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        long long b = 1;
        unordered_map<long long, bool> mm;
        for(int i=0;i<62;++i) {
            mm[b] = true;
            b *= (long long)2;
        }
        if(mm.find(N) != mm.end()) return true;
        vector<int> bits;
        int n = N;
        while(n > 0) {
            bits.push_back(n % 10);
            n /= 10;
        }
        sort(bits.begin(), bits.end());
        do {
            long long num = get_num(bits);
            if(mm.find(num) != mm.end()) return true;
        } while(next_permutation(bits.begin(), bits.end()));
        return false;
    }
    
    long long get_num(vector<int> & bits) {
        if(bits[0] == 0) return 0; //不能以0开头
        long long res = 0;
        long long bit = 1;
        for(int i=bits.size()-1;i>=0;--i) {
            res += (bits[i] * bit);
            bit *= 10;
        }
        return res;
    }
};
