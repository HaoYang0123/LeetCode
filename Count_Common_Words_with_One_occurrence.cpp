// Leetcode 2085

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> str2num1, str2num2;
        get_str_count(words1, str2num1);
        get_str_count(words2, str2num2);
        int res = 0;
        for(auto ind = str2num1.begin(); ind != str2num1.end(); ++ind) {
            if(ind->second == 1 && str2num2[ind->first] == 1) ++res;
        }
        return res;
    }
    
    void get_str_count(vector<string> & words, unordered_map<string, int> & str2num) {
        for(int i=0; i<words.size(); ++i) {
            str2num[words[i]]++;
        }
    }
};
