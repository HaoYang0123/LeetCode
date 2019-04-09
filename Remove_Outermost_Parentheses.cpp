//Leetcode 1021

class Solution {
public:
    string removeOuterParentheses(string S) {
        string res = "";
        stack<char> sta;
        for(int i=0;i<S.length();++i) {
            if(S[i] == '(') {
                if(!sta.empty()) res += "(";
                sta.push('(');
            }
            else {
                sta.pop();
                if(!sta.empty()) res += ")";
            }
        }
        return res;
    }
};
