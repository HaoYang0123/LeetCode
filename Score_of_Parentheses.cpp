//Leetcode 856

class Solution {
public:
    stack<int> sta;
    vector<int> map;
    int scoreOfParentheses(string S) {
        if(S.length()==0) return 0;
        int n = S.length();
        map.resize(n); //记录")"对应的"("的索引号，或者"("对应的")"的索引号
        for(int i=0;i<n;++i) {
            if(S[i]=='(') sta.push(i);
            else {
                map[i] = sta.top();
                map[sta.top()] = i;
                sta.pop();
            }
        }
        return get_score(S, 0, S.length() - 1);
    }
    int get_score(string & S, int start, int end) {
        if(start > end) return 0;
        if(start + 1 == end) return 1;
        int mid = map[start];
        if(mid < end)
            return get_score(S, start, mid) + get_score(S, mid + 1, end);
        return 2 * get_score(S, start + 1, end - 1);
    }
};
