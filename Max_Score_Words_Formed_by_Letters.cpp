//Leetcode 1255

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> c2num(26, 0);
        for(int i=0;i<letters.size();++i) {
            c2num[(int)(letters[i]-'a')]++;
        }
        vector<int> word_score(words.size(), 0);
        for(int i=0;i<words.size();++i) {
            word_score[i] = get_word_score(words[i], score);
        }
        return dfs(words, 0, c2num, word_score);
    }
    
    int get_word_score(string & word, vector<int> & score) {
        int s = 0;
        for(int i=0;i<word.length();++i) {
            s += score[int(word[i]-'a')];
        }
        return s;
    }
    
    int dfs(vector<string> & words, int start, vector<int> & c2num, vector<int> & score) {
        if(start >= words.size()) return 0;
        int no_gain = dfs(words, start+1, c2num, score);
        int gain = 0;
        string & cur_word = words[start];
        vector<int> new_c2num = c2num;
        if(is_ok(cur_word, new_c2num)) {
            gain = dfs(words, start+1, new_c2num, score) + score[start];
        }
        return max(gain, no_gain);
    }
    
    bool is_ok(string & word, vector<int> & c2num) {
        for(int i=0;i<word.length();++i) {
            int ind = int(word[i]-'a');
            --c2num[ind];
            if(c2num[ind] < 0) return false;
        }
        return true;
    }
};
