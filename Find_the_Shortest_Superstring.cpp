// Leetcode 943

class Solution {
public:
    map<pair<int, int>, int> mp;
    string shortestSuperstring(vector<string>& words) {
        int n=words.size();
        vector<vector<int>> graph(n, vector<int>(n, 0));
        //构建graph，graph[i][j]表示从words[i]与words[j]可以首尾相连的子字符串长度
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(i==j) continue;
                int k=min(words[i].length(), words[j].length());
                //cout<<"k\t"<<k<<endl;
                for(; k>0; --k) {
                    string first_sub = words[i].substr(words[i].length()-k);
                    string second_sub = words[j].substr(0,k);
                    //cout<<k<<"\t"<<first_sub<<"\t"<<second_sub<<endl;
                    if(first_sub == second_sub) {
                        graph[i][j] = k;
                        break;
                    }
                }
                //cout<<i<<"\t"<<j<<"\t"<<graph[i][j]<<endl;
            }
        }
        
        vector<vector<int>> dp(n, vector<int>((1<<n)+1, -1));
        int res_len = INT_MAX, res_idx = -1;
        for(int i=0; i<n; ++i) {
            int cur = (1<<i);
            int tmp = int(words[i].length())+dfs(i, cur, words, graph, dp);
            if(tmp<res_len) {
                res_len = tmp;
                res_idx = i;
            }
        }
        string res = words[res_idx];
        int cur = (1<<res_idx);
        while(mp.find({res_idx, cur}) != mp.end()) {
            auto idx2 = mp.find({res_idx, cur});
            int nxt_idx = idx2->second;
            res += words[nxt_idx].substr(graph[res_idx][nxt_idx]);
            res_idx = nxt_idx;
            cur |= (1<<nxt_idx);
        }
        return res;
    }
    
    int dfs(int start, int cur, vector<string> & words, vector<vector<int>> & graph, vector<vector<int>> & dp) {
        //cout<<start<<":"<<cur<<endl;
        if(dp[start][cur] != -1) return dp[start][cur];
        int n=graph.size();
        if(cur == (1<<n)-1) return 0;  //如果所有结点都走过了，则直接返回0
        int res = INT_MAX, min_idx=-1;
        for(int i=0; i<n; ++i) {
            if((cur & (1<<i)) != 0) continue;  //已经走过i结点，不能再走了
            int tmp = words[i].length() - graph[start][i] + dfs(i, cur | (1<<i), words, graph, dp);
            if(tmp<res) {
                res = tmp;
                min_idx=i;
            }
        }
        dp[start][cur] = res;
        mp[{start,cur}] = min_idx;
        return res;
    }
};
