// Leetcode 2284

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> user2num;
        for(int i=0; i<senders.size(); ++i) {
            string & name = senders[i];
            string & sent = messages[i];
            user2num[name] += get_word_num(sent);
        }
        map<int, vector<string>> all_users;
        for(auto idx=user2num.begin(); idx!=user2num.end(); ++idx) {
            all_users[idx->second].push_back(idx->first);
        }
        auto idx = all_users.end();
        --idx;  //最大的单词数量
        vector<string> & largest_users = idx->second;
        sort(largest_users.rbegin(), largest_users.rend());
        return largest_users[0];
    }
    
    inline int get_word_num(string & sent) {
        int res = 0;
        for(int i=0; i<sent.length(); ++i) {
            if(sent[i]==' ') ++res;
        }
        return res+1;
    }
};
