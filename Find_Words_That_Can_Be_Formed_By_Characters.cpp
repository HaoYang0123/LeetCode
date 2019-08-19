//Leetcode 1160

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> aa2num(26, 0);
        for(int i=0;i<chars.length();++i) 
            aa2num[int(chars[i]-'a')]++;
        int res = 0;
        for(int i=0;i<words.size();++i) {
            if(is_ok(aa2num, words[i])) res += words[i].length();
        }
        return res;
    }
    
    bool is_ok(vector<int> & aa2num, string & word) {
        vector<int> new_aa2num(26, 0);
        for(int i=0;i<word.length();++i) {
            int ind = int(word[i]-'a');
            new_aa2num[ind]++;
            if(new_aa2num[ind] > aa2num[ind]) return false;
        }
        return true;
    }
};
