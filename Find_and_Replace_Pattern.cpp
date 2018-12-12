//Leetcode 890

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(int i=0;i<words.size();++i) {
            vector<int> map(26, -1), map2(26, -1);
            bool flag = true;
            for(int j=0;j<pattern.length();++j) {
                int newInd = int(pattern[j] - 'a');
                int ind = int(words[i][j] - 'a');
                if (map[ind] != -1 && map[ind] != newInd) {
                    flag = false;
                    break;
                }
                if (map2[newInd] != -1 && map2[newInd] != ind) {
                    flag = false;
                    break;
                }
                map[ind] = newInd;
                map2[newInd] = ind;
            }
            if(flag) res.push_back(words[i]);
        }
        return res;
    }
};
