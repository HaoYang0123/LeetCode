// Leetcode 1447

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        for(int i=2; i<=n; ++i) {
            for(int j=1; j<i; ++j) {
                if(can_join(i, j)) {
                    string fz = to_string(j), fm = to_string(i);
                    res.push_back(fz+"/"+fm);
                }
            }
        }
        return res;
    }
    
    inline bool can_join(int i, int j) {
        //i是分母，j是分子
        for(int k=2; k<=j; ++k) {
            if(i%k==0 &&j%k==0) return false;
        }
        return true;
    }
};
