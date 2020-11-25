//Leetcode 1662

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        return get_str(word1) == get_str(word2);
    }
    
    inline string get_str(vector<string> & w) {
        string res = "";
        for(int i=0;i<w.size();++i) {
            res += w[i];
        }
        return res;
    }
};
