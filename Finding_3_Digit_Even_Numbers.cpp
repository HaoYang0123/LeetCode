// Leetcode 2094

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> res;
        unordered_set<int> ss;  //去冗余
        for(int i=0; i<digits.size(); ++i) {
            if(digits[i] == 0) continue;  //不能以0开始
            for(int j=0; j<digits.size(); ++j) {
                if(j == i) continue;
                for(int k=0; k<digits.size(); ++k) {
                    if(k == i || k == j) continue;
                    if(digits[k] % 2 != 0) continue;  //不是偶数
                    int tmp = digits[i]*100 + digits[j]*10 + digits[k];
                    if (ss.find(tmp) != ss.end()) continue;
                    ss.insert(tmp);
                    res.push_back(tmp);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
