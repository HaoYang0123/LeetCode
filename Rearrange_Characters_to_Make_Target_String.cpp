class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> scount(26, 0);
        vector<int> tcount(26, 0);
        for(int i=0; i<s.length(); ++i) {
            scount[int(s[i] - 'a')]++;
        }
        for(int i=0; i<target.length(); ++i) {
            tcount[int(target[i]-'a')]++;
        }
        int res = INT_MAX;
        for(int i=0; i<26; ++i) {
            if(tcount[i] > 0) {
                int tmp = scount[i] / tcount[i];
                res = min(res, tmp);
            }
        }
        return res;
    }
};
