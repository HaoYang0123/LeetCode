// Leetcode 1668

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        unordered_set<string> all_substr;
        for(int i=0; i<sequence.length(); ++i) {
            string cur = "";
            for(int j=i; j<sequence.length(); ++j) {
                cur += sequence[j];
                all_substr.insert(cur);
            }
        }
        int res = 0;
        string cur_w = "";
        for(int i=1; i<=sequence.length()/word.length(); ++i) {
            cur_w += word;
            if(all_substr.find(cur_w) != all_substr.end()) res = i;
        }
        return res;
    }
};
