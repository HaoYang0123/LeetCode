//Leetcode 1081

class Solution {
public:
    string smallestSubsequence(string text) {
        int n=text.length();
        vector<int> dp(n, 0); //表示对应位置的Flag,为1则表示是最后一个元素（必须插入），为2则表示不考虑（因为之前已经将其插入）
        unordered_map<char, int> mm, mm2; //mm[c]表示c在text中最后的索引位置，mm2表示当前res中包含的元素
        for(int i=n-1;i>=0;--i) { //注意：是从后往前扫描
            if(mm.find(text[i]) == mm.end()) {
                mm[text[i]] = i;
                dp[i] = 1;
            }
        }
        //cout<<"MM:\t"<<mm.size()<<endl;
        string res = "";
        int start = 0;
        while(res.length() < mm.size()) {
            int cur_index = find_one(text, start, dp, mm2);
            //cout<<cur_index<<"\t"<<text[cur_index]<<"\t"<<mm[text[cur_index]]<<endl;
            res += text[cur_index];
            mm2[text[cur_index]] = 1; //表示text[cur_index]已经插入
            dp[mm[text[cur_index]]] = 2; //更新dp，因为text[cur_index]已经插入，后面的不考虑
            start = cur_index + 1;
        }
        return res;
    }
    
    int find_one(string & text, int i, vector<int> & dp, unordered_map<char, int> & mm2) { //从i找下一个位置
        while(i<dp.size() && mm2.find(text[i]) != mm2.end()) ++i; //如果i已经在mm2中，则不考虑
        if(i>=dp.size()) return -1;
        char c=text[i];
        int j=i+1;
        int res = i;
        if(dp[i]==1) return res; //dp[i]等于1，表示text[i]已经是最后一个了，错过了就没了，所以必须插入
        while(j<dp.size()) {
            if(mm2.find(text[j]) != mm2.end()) {
                ++j;
                continue;
            }
            if(text[j]<c) {
                c = text[j];
                res = j;
            }
            if(dp[j]==1) break;
            ++j;
        }
        return res;
    }
};
