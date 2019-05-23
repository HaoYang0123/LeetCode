// Leetcode 1047

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> sta;
        for(int i=0;i<S.length();++i) {
            if(sta.empty()) sta.push(S[i]);
            else {
                char t=sta.top();
                if (t==S[i]) sta.pop();
                else sta.push(S[i]);
            }
        }
        string res = "";
        while(!sta.empty()) {
            res += sta.top();
            sta.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
