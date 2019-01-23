//Leetcode 966

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, vector<string>> mm;
        for(int i=0;i<wordlist.size();++i) {
            string s = to_lower(wordlist[i]);
            set<string> all;
            string cur_str = "";
            dfs(s, 0, cur_str, all);
            for(auto ind = all.begin(); ind != all.end(); ++ind) {
                string c = *ind;
                vector<string> tmp;
                if(mm.find(c) != mm.end()) tmp = mm[c];
                tmp.push_back(wordlist[i]);
                mm[c] = tmp;
            }
        }
        vector<string> res;
        for(int i=0;i<queries.size();++i) {
            string q = to_lower(queries[i]);
            auto ind = mm.find(q);
            if(ind == mm.end()) {
                res.push_back("");
                continue;
            }
            vector<string> values = ind->second;
            bool is_in = false;
            for(int j=0;j<values.size();++j) {
                if(values[j]==queries[i]) {
                    is_in = true;
                    res.push_back(values[j]);
                    break;
                }
                
            }
            if(is_in) continue;
            for(int j=0;j<values.size();++j) {
                if(q==to_lower(values[j])) {
                    is_in = true;
                    res.push_back(values[j]);
                    break;
                }
            }
            if(is_in) continue;
            res.push_back(values[0]);
        }
        return res;
    }
    
    string to_lower(string & str) {
        string res="";
        for(int i=0;i<str.length();++i) {
            if(str[i]>='A' && str[i]<='Z') 
                res += (char)('a'+(int)(str[i]-'A'));
            else
                res += str[i];
        }
        return res;
    }
    void dfs(string & str, int i, string & cur_str, set<string> & res) {
        if(i == str.length()) {
            res.insert(cur_str);
            return;
        }
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u') {
            string new_str = cur_str + 'a';
            dfs(str, i+1, new_str, res);
            new_str = cur_str + 'e';
            dfs(str, i+1, new_str, res);
            new_str = cur_str + 'i';
            dfs(str, i+1, new_str, res);
            new_str = cur_str + 'o';
            dfs(str, i+1, new_str, res);
            new_str = cur_str + 'u';
            dfs(str, i+1, new_str, res);
        }
        else {
            string new_str = cur_str + str[i];
            dfs(str, i+1, new_str, res);
        }
    }
};
