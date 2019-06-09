//Leetcode 5083

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        string old = "", cur = "";
        int flag = 0;  //0是匹配第1个，1是匹配第2个，3是前两个都匹配上
        for(int i=0;i<text.length();++i) {
            if(text[i] != ' ') cur += text[i];
            else {
                //cout<<cur<<"\t"<<flag<<endl;
                if(flag == 0) {
                    if(cur == first)
                        flag = 1;
                }
                else if(flag == 1) {
                    //cout<<cur<<"\t"<<second<<endl;
                    if(cur == second)
                        flag = 2;
                    else if(cur == first) flag = 1;
                    else flag = 0;
                }
                else if(flag == 2) {
                    res.push_back(cur);
                    if(old == first && cur == second) flag = 2;
                    else if(cur == first) flag = 1;
                    else flag = 0;
                }
                old = cur;
                cur = "";
            }
        }
        if(cur != "" && flag == 2) res.push_back(cur); 
        return res;
    }
};
