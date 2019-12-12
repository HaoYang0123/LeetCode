//Leetcode 30

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
		if(words.size() == 0 || s.length() == 0) return res;
        int n = words[0].length();
        if(s.length() < n * words.size()) return res;
        unordered_map<string, int> word2num, word2num_ori;
        for(int i=0;i<words.size();++i) word2num[words[i]]++;
        for(int i=0;i<=s.length() - n * words.size(); ++i) {
            unordered_map<string, int> tmp = word2num;
            if(is_ok(tmp, s, i, i + n * words.size(), n)) res.push_back(i);
        }
        return res;
    }

    inline bool is_ok(unordered_map<string, int> & word2num, string & s, int start, int end, int n) {
        for(int i=start;i<end;i+=n) {
            string sub_s = s.substr(i, n);
            if(word2num.find(sub_s) == word2num.end()) return false;
            --word2num[sub_s];
            if(word2num[sub_s] < 0) return false;
        }
        return true;
    }
};
