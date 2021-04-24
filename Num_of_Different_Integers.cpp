// Leetcode 1805

class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> ss;
        string cur_dig = "";
        for(int i=0; i<word.length(); ++i) {
            if(word[i] >= '0' && word[i] <= '9') {
                cur_dig += word[i];
            }
            else {
                if(cur_dig != "") {
                    ss.insert(delete_leading_zero(cur_dig));
                }
                cur_dig = "";
            }
        }
        if(cur_dig != "") {
            ss.insert(delete_leading_zero(cur_dig));
        }
        return ss.size();
    }
    
    inline string delete_leading_zero(const string & word) {
        int i = 0;
        while(i < word.length() && word[i] == '0') ++i;
        if (i == word.length()) return "0";
        return word.substr(i);
    }
};
