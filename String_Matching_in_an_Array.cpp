//Leetcode 1408

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for(int i=0;i<words.size();++i) {
            string & one = words[i];
            bool find = false;
            for(int j=0;j<words.size();++j) {
                if(words[j].length() <= one.length()) continue;
                int ind = words[j].find(one);
                if(ind != string::npos){
                    find = true;
                    break;
                }
            }
            if(find) res.push_back(one);
        }
        return res;
    }
};
