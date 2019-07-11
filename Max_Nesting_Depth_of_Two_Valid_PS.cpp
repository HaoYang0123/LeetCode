//Leetcode 1111
//使用3次扫描，第1次记录(和)对应位置关系(代码中的m1和m2)
//第2次记录各个(对应的值及整个字符串中的最大的值（代码中的dp和final_max）
//第3次更新结果，将(对应的值比final_max/2大的归为A，另外的归为B（反之亦然）

//感觉2次扫描即可，前两次可以做的找对应关系及记录(的值

class Solution {
public:
    unordered_map<int, int> m1, m2; //m1和m2分别记录左和右括号的对应关系
    int final_max;
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.length();
        stack<int> sta;
        for(int i=0;i<n;++i) {
            if(seq[i] == '(') sta.push(i);
            else {
                int z=sta.top();
                sta.pop();
                m1[z] = i;
                m2[i] = z;
            }
        }
        //for(auto ind = m1.begin(); ind != m1.end(); ++ind) cout<<ind->first<<"\t"<<ind->second<<endl;
        vector<int> dp(n,0);
        int start = 0;
        final_max = 0;
        int end = m1[start];
        while(start<n) {
            dfs(start, dp);
            start = end+1;
            end = m1[start];
        }
        //for(int i=0;i<n;++i) cout<<seq[i]<<"\t"<<dp[i]<<endl;
        vector<int> res(n,0);
        int flag = final_max/2;
        for(int i=0;i<n;++i) {
            if(seq[i]=='(') {
                if(dp[i]>flag) res[i]=1;
            }
            else {
                int j=m2[i];
                res[i]=res[j];
            }
        }
        return res;
    }
    
    int dfs(int i, vector<int> & dp) {
        if(dp[i] != 0) return dp[i];
        int j=m1[i];
        if(i+1==j) {
            dp[i] = 1;
            final_max = max(final_max, 1);
            return 1; //如果是"()",则返回1
        }
        int max_v = 0;
        int start=i+1, end=m1[start];
        while(start<j) {
            int tmp=dfs(start, dp);
            if(tmp > max_v) max_v = tmp;
            start = end + 1;
            end = m1[start];
        }
        dp[i] = max_v+1;
        final_max = max(final_max, max_v+1);
        return max_v+1;
    }
};
