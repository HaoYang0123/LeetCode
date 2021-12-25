// Leetcode 2110

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        prices.push_back(prices.back());
        long long res = 0;
        int c = 1;
        for(int i=1; i<prices.size(); ++i) {
            if(prices[i] == prices[i-1]-1) ++c;
            else {
                res += get_v(c);
                c = 1;
            }
        }
        return res;
    }
    
    inline long long get_v(long long n) {
        return n*(n+1)/2;
    }
};
