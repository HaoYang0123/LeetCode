// Leetcode 1897

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> c2n;
        for(int i=0; i<words.size(); ++i) {
            string & w = words[i];
            for(int j=0; j<w.length(); ++j) {
                c2n[w[j]]++;
            }
        }
        for(auto idx = c2n.begin(); idx != c2n.end(); ++idx) {
            int count = idx->second;
            if(count % words.size() != 0) return false;
        }
        return true;
    }
};
