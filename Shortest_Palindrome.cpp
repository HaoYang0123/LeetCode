//Leetcode 214
//Manacher算法找最长回文串

//最近看了一下KMP，重新用KMP思路实现了一遍
class Solution {
public:
    string shortestPalindrome(string s) {
        string revs = s;
        reverse(revs.begin(), revs.end());
        string new_s = s + "#" + revs;
        vector<int> pattern(new_s.length(), 0);
        get_pattern(new_s, pattern);
        int max_len = pattern[new_s.length()-1];
        int ori_len = s.length();
        if(max_len == ori_len) return s; //说明s本身就是回文串
        string need_str = s.substr(max_len, ori_len-max_len);
        reverse(need_str.begin(), need_str.end());
        return need_str + s;
    }
    
    //KMP算法思路，给定字符串str，计算pattern[i]为str[0...i]的最长的、相等的前缀和后缀子串
    void get_pattern(string & str, vector<int> & pattern) {
        int cur_max_len = 0;
        for(int i=1;i<str.length();++i) {
            while(cur_max_len > 0 && str[cur_max_len] != str[i]) 
                cur_max_len = pattern[cur_max_len-1];
            if(str[cur_max_len] == str[i]) ++cur_max_len;
            pattern[i] = cur_max_len;
        }
    }
};

//好早之前写过的算法
class Solution {
public:
    string shortestPalindrome(string s) {
        string new_s = preprocess(s);
        int mx = -1, mid = 0;
        //Manacher算法
        vector<int> p(new_s.length(), 1); //p[i]表示以i为回文串的中心，回文串的半径
        int good_i = -1;
        for(int i=0;i<new_s.length();++i) {
            if(i<mx) p[i] = min(p[2*mid-i], mx-i);
            while(i-p[i] >= 0 && i+p[i] < new_s.length() && new_s[i-p[i]] == new_s[i+p[i]]) p[i]++;
            if(i+p[i] > mx) {
                mx = i+p[i];
                mid = i;
            }
            if(i+1 == p[i]) good_i = i; //如果p[i]==i+1，表示i为回文串中心时，左端是new_s字符串的开头，右端为good_i+p[good_i]-1
        }
        //cout<<mid<<"\t"<<mx<<endl;
        //for(int i=0;i<new_s.length();++i) cout<<i<<"\t"<<p[i]<<endl;
        string res = "";
        for(int i=good_i + p[good_i]; i<new_s.length();++i) {
            if(new_s[i] != '#') res += new_s[i];
        }
        reverse(res.begin(), res.end());
        for(int i=1;i<new_s.length();i+=2) res += new_s[i];
        return res;
    }
    
    string preprocess(string & s) {
        char res[s.length()*2+2];
        int j=0;
        for(int i=0;i<s.length();++i) {
            res[j++] = '#';
            res[j++] = s[i];
        }
        res[j++] = '#';
        res[j++] = '\0';
        return res;
    }
};
