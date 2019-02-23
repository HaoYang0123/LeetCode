//Leetcode 869
//第一种思路是枚举N的全排列
//末尾的算法时间复杂度更小，思路也更加清晰

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


//另一种方式，记录1，2，4，8，16,...,的每位的数目
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        vector<int> bits(10, 0);
        int bb = 0;
        int n = N;
        while(n>0) {
            ++bb;
            int b = n%10;
            ++bits[b];
            n/=10;
        }
        int num = 1;
        for(int i=0;i<30;++i) {
            bool flag = is_ok(num, bits, bb);
            if(flag) return true;
            num *= 2;
        }
        return false;
    }
    
    bool is_ok(int num, vector<int> & bits, int bb) {
        vector<int> new_bits(10, 0);
        int bit_num = 0;
        while(num>0) {
            ++bit_num;
            int b=num%10;
            ++new_bits[b];
            if(new_bits[b] > bits[b]) return false;
            num /= 10;
        }
        //cout<<num<<"\t"<<bit_num<<endl;
        return (bit_num == bb);
    }
};
