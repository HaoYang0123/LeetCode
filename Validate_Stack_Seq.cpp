//Leetcode 946

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int pi=0;
        stack<int> sta;
        for(int i=0;i<pushed.size();++i) {
            sta.push(pushed[i]);
            while(!sta.empty() && sta.top() == popped[pi]) {
                sta.pop();
                ++pi;
            }
        }
        return pi==popped.size();
    }
};
