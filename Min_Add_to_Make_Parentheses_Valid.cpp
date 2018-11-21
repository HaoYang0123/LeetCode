//Leetcode 921

class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> sta;
        int res=0;
        for(int i=0;i<S.length();++i) {
          if(S[i] == '(') {
            sta.push('(');
          }
          else {
            if(sta.empty()) ++res;
            else sta.pop();
          }
        }
        res += sta.size();
        return res;
    }
};
