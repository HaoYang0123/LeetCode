//Leetcode 1048

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<vector<string>> len_words(17, vector<string>()); //len_words[i]表示长度为i的words
        unordered_map<string, int> dp; //dp[word]表示从word出发的最长结果
        //int min_index = INT_MAX;
        for (int i=0;i<words.size(); ++i) {
            int len = words[i].length();
            len_words[len].push_back(words[i]);
            //cout<<words[i]<<"\t"<<len<<endl;
            //if (len < min_index) min_index=len;
        }
        int res = 1;
        
        for(int i=0;i<words.size();++i) {
            int cur_index = words[i].length();
            //cout<<"Start\t"<<cur_index<<"\t"<<words[i]<<endl;
            res = max(res, dfs(len_words, words[i], cur_index, dp));
        }
        return res;
    }
    
    int dfs(vector<vector<string>> & len_words, string & cur_word, int index, unordered_map<string, int> & dp) {
        if(dp.find(cur_word) != dp.end()) return dp[cur_word];
        if(index >= len_words.size()-1 || len_words[index+1].size() == 0) {
            dp[cur_word] = 1;
            return 1;
        }
        vector<string> next_words = len_words[index+1]; //当前cur_word的长度是index，下一个结点只能从长度为index+1的候选中得到
        int tmp = 0;
        for(int i=0;i<next_words.size();++i) {
            //cout<<cur_word<<"\t"<<next_words[i]<<"\t"<<is_edge(cur_word, next_words[i])<<endl;
            if(!is_edge(cur_word, next_words[i])) continue;
            tmp = max(tmp, dfs(len_words, next_words[i], index+1, dp));
        }
        dp[cur_word] = tmp + 1;
        return tmp + 1;
    }
    
    bool is_edge(string & a, string & b) { //a的长度比b小1，判断a与b是否连边
        int i=0,j=0;
        bool is_same = true;
        while(i<a.length() && j<b.length()) {
            if(a[i] == b[j]) {
                ++i;
                ++j;
            }
            else {
                if(!is_same) return false;
                is_same = false;
                ++j;
            }
        }
        return true;
    }
};
