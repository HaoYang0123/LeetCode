//Leetcode 767

class Solution {
public:
    string reorganizeString(string S) {
        vector<int> mm(26, 0);
        for(int i=0;i<S.length();++i) {
            mm[(int)(S[i]-'a')]++;
        }
        int max_v=0, max_index = -1;
        for(int i=0;i<26;++i) {
            if(mm[i]>max_v) {
                max_v = mm[i];
                max_index = i;
            }
        }
        if(max_v > (S.length()+1)/2) return "";
        int tmp = -1;
        string res = "";
        for(int i=0;i<S.length();++i) {
            res += (char)('a'+max_index);
            mm[max_index]--;
            tmp = max_index;
            max_v = 0;
            for(int j=0;j<26;++j) {
                if(tmp==j) continue;
                if(mm[j] > max_v) {
                    max_v = mm[j];
                    max_index = j;
                }
            }
        }
        return res;
    }
};
