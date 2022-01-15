// Leetcode 2135

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> ss;
        for(int i=0; i<startWords.size(); ++i) {
            string w = startWords[i];
            sort(w.begin(), w.end());
            ss.insert(w);
        }
        int res = 0;
        for(int i=0; i<targetWords.size(); ++i) {
            string w = targetWords[i];
            sort(w.begin(), w.end());
            string left = "";
            for(int j=0; j<w.length(); ++j) {
                string neww = left + w.substr(j+1);
                left += w[j];
                if(ss.find(neww) != ss.end()) {
                    ++res;
                    break;
                }
            }
        }
        return res;
    }
};
