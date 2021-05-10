// Leetcode 1849

class Solution {
public:
    bool res;
    bool splitString(string s) {
        res = false;
        int i=0;
        while(i < s.length() && s[i] == '0') ++i;  //需要将前缀的0去掉，这样才能使用折半来字符串来处理了
        s = s.substr(i);
        if(s.length() <= 1) return false;  // "001"这种，去掉前缀0后，只有一个字符，这种必然为false
        string cur_s = "";
        //这里，使用折半字符串处理，因为防止long long溢出，因为s总长度是20，折半处理后最长才10，这样long long不会溢出
        for(int i=0; i<(s.length()+1)/2; ++i) { //i不能等于s.length()-1，如果等于了，那么就相当于只有一个数字，显然res永远为true
            cur_s += s[i];
            long long cur_digit = stoll(cur_s);
            dfs(s, i+1, cur_digit);
        }
        return res;
    }
    
    void dfs(string s, int i, long long cur_digit) {
        //cout<<cur_digit<<endl;
        if(res) return;
        if(i >= s.length()) {
            res = true;
            return;
        }
        string cur_s = "";
        for(int k=i; k<s.length(); ++k) {
            cur_s += s[k];
            long long new_digit = stoll(cur_s);
            if(new_digit == cur_digit - 1) {
                dfs(s, k+1, new_digit);
            }
            else if(new_digit > cur_digit - 1) break;
        }
    }
};
