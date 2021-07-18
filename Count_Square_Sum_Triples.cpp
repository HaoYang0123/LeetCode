// Leetcode 1925

class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        int n2 = n*n;
        unordered_set<int> ss;
        for(int i=1; i<=n; ++i) ss.insert(i*i);
        for(int a=1; a<=n; ++a) {
            for(int b=1; b<=n; ++b) {
                int c2 = a*a+b*b;
                if(c2 > n2) break;
                if(ss.find(c2) != ss.end()) ++res;
            }
        }
        return res;
    }
};
