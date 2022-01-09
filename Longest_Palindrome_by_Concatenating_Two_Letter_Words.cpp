// Leetcode 2131

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> w2c;
        for(int i=0; i<words.size(); ++i) w2c[words[i]]++;
        int res = 0;
        int max_cc = 0;
        //cout<<"size\t"<<w2c.size()<<endl;
        vector<string> keys;
        for(auto idx = w2c.begin(); idx != w2c.end(); ++idx) keys.push_back(idx->first);
        for(int i = 0; i < keys.size(); ++i) {  //为啥这个for循环走不完就结束了？？？
            string w = keys[i];
            int cur_c = w2c[w];
            //cout<<w<<"\t"<<cur_c<<endl;
            if(w[0] == w[1]) {
                if(cur_c % 2 != 0) max_cc = 1;
                res += (cur_c/2) * 4;
                //cout<<w<<"\t"<<cur_c<<"\t"<<res<<endl;
            }
            else if(w[0] < w[1]) {
                string nw = "";
                nw += w[1];
                nw += w[0];
                res += min(cur_c, w2c[nw]) * 4;
            }
        }
        //cout<<res<<"\t"<<max_cc<<endl;
        return res+max_cc*2;
    }
};
