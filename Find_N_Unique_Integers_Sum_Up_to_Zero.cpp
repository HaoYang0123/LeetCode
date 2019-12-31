//Leetcode 1304

class Solution {
public:
    vector<int> sumZero(int n) {
        int div_num = n/2;
        vector<int> res;
        for(int i=1;i<=div_num;++i) {
            res.push_back(i);
            res.push_back(-i);
        }
        if(n%2 == 1) res.push_back(0);
        return res;
    }
};
