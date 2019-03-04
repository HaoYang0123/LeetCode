//Leetcode 1003
//类似"()"的问题，括号的合法性，比如：((()()))合法，abc只是多了个，三个元素的合法性。
//同样，使用栈来求解（时间复杂度O(N)），如果遇到a，则入栈，如果遇到b，如果栈顶是a，则入栈（否则返回false）
//如果遇到c，如果栈顶是b，则弹出两个元素（"b"和"a"将被弹出）。最终，需要判断栈是否为空，比如仅ab两个元素的字符串则是非法的。

class Solution {
public:
    bool isValid(string S) {
        stack<char> sta;
        for(int i=0;i<S.length();++i) {
            char c = S[i];
            if(c=='a') sta.push(c);
            else if(c=='b') {
                if(sta.empty()) return false;
                char t = sta.top();
                if(t != 'a') return false;
                sta.push(c);
            }
            else { //'c'
                if(sta.empty()) return false;
                char t = sta.top();
                if(t != 'b') return false;
                sta.pop();
                sta.pop();
            }
        }
        return sta.empty();
    }
};
