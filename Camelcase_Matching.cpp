//Leetcode 1023

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res(queries.size(), false);
        for(int i=0;i<queries.size();++i) {
            if(match(queries[i], pattern)) res[i] = true;
        }
        return res;
    }
    
    bool match(string & q, string & p) {
        int qi = 0, pi = 0;
        while(qi<q.length()&&pi<p.length()) {
            if(q[qi]==p[pi]) {
                qi++;
                pi++;
            }
            else {
                if(q[qi]>='A'&&q[qi]<='Z') {
                    return false;
                }
                else qi++;
            }
        }
        if(pi<p.length()) return false;
        while(qi<q.length()) {
            if(q[qi]>='A'&&q[qi]<='Z') return false;
            qi++;
        }
        return true;
    }
};
