// Leetcode 1720

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res(encoded.size()+1, 0);
        res[0] = first;
        for(int i=1;i<res.size();++i) {
            res[i] = res[i-1] ^ encoded[i-1];
        }
        return res;
    }
};
