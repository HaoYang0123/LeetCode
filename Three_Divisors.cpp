// Leetcode 1952

class Solution {
public:
    bool isThree(int n) {
        set<int> div;
        for(int i=1; i<=n/2;++i) {
            if(n % i == 0) {
                div.insert(i);
                div.insert(n/i);
            }
        }
        return div.size() == 3;
    }
};
