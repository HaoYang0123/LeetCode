//Leetcode 792
//第一套代码超时了，第二套代码可以AC

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<int>> dp(26, vector<int>());
        for(int i=0;i<S.length();++i) {
            dp[S[i]-'a'].push_back(i);
        }
        vector<vector<int>> dp2(S.length(), vector<int>(26, -1));
        for(int i=0;i<S.length();++i) {
            for(int j=0;j<26;++j) {
                vector<int> indexes=dp[j];
                auto ind=upper_bound(indexes.begin(), indexes.end(), i);
                if(ind != indexes.end()) dp2[i][j]=(*ind);
            }
        }
        int res = 0;
        for(int i=0;i<words.size();++i) {
            string w=words[i];
            char c=w[0];
            if(dp[c-'a'].size()==0) continue;
            int ind=dp[c-'a'][0];
            bool is_ok=true;
            for(int j=1;j<w.length();++j) {
                char c=w[j];
                ind=dp2[ind][c-'a'];
                if(ind==-1) {
                    is_ok=false;
                    break;
                }
            }
            if(is_ok) ++res;
        }
        return res;
    }
};

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<int>> dp(26, vector<int>());
        for(int i=0;i<S.size();i++) {
            dp[S[i]-'a'].push_back(i);
        }
        
        int res=0;
        for(int i=0;i<words.size();i++) {
            //string w=words[i];
            int prev=-1;
            bool found=true;
            for(int j=0;j<words[i].size();j++) {
                //vector<int> v=dp[w[j]-'a'];
                if(dp[words[i][j]-'a'].size()==0) {
                    found=false;
                    break;
                }
                auto ind=upper_bound(dp[words[i][j]-'a'].begin(),dp[words[i][j]-'a'].end(),prev);
                if(ind==dp[words[i][j]-'a'].end()) {
                    found=false;
                    break;
                }
                else prev=*ind;
            }
            if(found) ++res;
        }
        return res;
    }
};
