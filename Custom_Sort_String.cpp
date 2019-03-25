//Leetcode 791

class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> dp(26, 0); //存储T中a-z的个数
        for(int i=0;i<T.length();++i) {
            dp[T[i]-'a']++;
        }
        string res="";
        set<char> ss;
        for(int i=0;i<S.length();++i) {
            int ind=(int)(S[i]-'a');
            for(int j=0;j<dp[ind];++j) {
                res+=S[i];
            }
            ss.insert(S[i]);
        }
        for(int i=0;i<T.length();++i) {
            auto ind=ss.find(T[i]);
            if(ind!=ss.end()) continue;
            res+=T[i];
        }
        return res;
    }
};
