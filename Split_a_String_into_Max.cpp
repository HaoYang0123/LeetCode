//Leetcode 1593

class Solution {
public:
    int res;
    int maxUniqueSplit(string s) {
        res = INT_MIN;
        unordered_set<string> ss;
        dfs(s, 0, ss);
        return res;
    }
    
    void dfs(string s, int i, unordered_set<string> & ss) {
        if(i >= s.length()) {
            res = max(res, (int)ss.size());
            //cout<<"------"<<endl;
            //for(auto ind=ss.begin();ind!=ss.end();++ind) cout<<*ind<<endl;
            return;
        }
        string cur_s = "";
        for(int j=i;j<s.length();++j) {
            cur_s += s[j];
            if(ss.find(cur_s) != ss.end()) continue;
            ss.insert(cur_s);
            dfs(s, j+1, ss);
            ss.erase(cur_s);
        }
    }
};
