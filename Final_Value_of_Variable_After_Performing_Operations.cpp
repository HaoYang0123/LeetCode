// Leetcode 2011

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for(int i=0; i<operations.size(); ++i) {
            if(operations[i][0] == '+' || operations[i][2] == '+') ++res;
            else --res;
        }
        return res;
    }
};
