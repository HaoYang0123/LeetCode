//Leetcode 1106
//使用栈来解决：如果是','，不考虑，如果是'(', 't', 'f', '&', '|', '!',则入栈
//如果是')'，则将'('到栈顶的元素考虑(这些元素只能是't'或者'f')，然后根据在'('前的是'&', '|', '!'，将'('至')'的结果入栈
//最后栈中只有一个结果（'t'或者'f')

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> sta;
        for(int i=0;i<expression.length();++i) {
            if(expression[i]==',') continue;
            else if(expression[i]!=')') sta.push(expression[i]);
            else {
                int t_num=0,f_num=0;
                while(!sta.empty()&&sta.top()!='(') {
                    char t=sta.top();
                    sta.pop();
                    if(t=='t') ++t_num;
                    else if(t=='f') ++f_num;
                }
                sta.pop(); //'('去掉
                char flag = sta.top();
                sta.pop();
                if (flag == '|') {
                    if(t_num>0) sta.push('t');
                    else sta.push('f');
                }
                else if(flag == '&') {
                    if(f_num==0) sta.push('t');
                    else sta.push('f');
                }
                else if(flag == '!') {
                    if(t_num>0) sta.push('f');
                    else sta.push('t');
                }
            }
        }
        return sta.top() == 't' ? true : false;
    }
};
