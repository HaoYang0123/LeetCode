//Leetcode 1528

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string new_s = s;
        for(int i=0;i<indices.size();++i) {
            new_s[indices[i]] = s[i];
        }
        return new_s;
    }
};
