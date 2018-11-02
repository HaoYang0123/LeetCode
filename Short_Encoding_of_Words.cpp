//Leetcode 820
//Trie树，字典树

class Node {
public:
    char v;
    Node* next[26];

public:
    Node(char c) {
        this->v = c;
        for(int i=0;i<26;++i) this->next[i]=NULL;
    }
};

bool cmp(const string & a, const string & b) {
    return a.length() > b.length();
}

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), cmp); //需要按长度从大到小排序，那么如果长度长的字符串已经存储，短的字符串可能是其后缀形式，则不用考虑
        Node* root=new Node(' ');
        Node* cur = root;
        for(int i=words[0].length()-1;i>=0;--i) {
            cur->next[words[0][i]-'a'] = new Node(words[0][i]);
            cur = cur->next[words[0][i]-'a'];
        }
        int res = words[0].length()+1;
        for(int i=1;i<words.size();++i) {
            Node* cur = root;
            bool is_in = true;
            string word = words[i];
            for(int j=word.length()-1;j>=0;--j) {
                if(cur->next[word[j]-'a'] != NULL) cur = cur->next[word[j]-'a'];
                else {
                    is_in = false;
                    cur->next[word[j]-'a'] = new Node(word[j]);
                    cur = cur->next[word[j]-'a'];
                }
            }
            if(!is_in) res += (word.length()+1);
        }
        return res;
    }
};
