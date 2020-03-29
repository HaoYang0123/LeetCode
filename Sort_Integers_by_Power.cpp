//Leetcode 1387
//优化队列：push插入pair（构建pair可以用{}），默认排序是按照pair的first从小至大排序，pop倒序输出

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        unordered_map<int,int> dp;
        priority_queue<pair<int, int>> pq;
        for(int i=lo; i<=hi;++i) {
            int r = get_power(i, dp);
            pq.push({r,i});
        }
        int count = pq.size()-k;
        while(count--) {
            pq.pop();
        }
        //for(int i=0;i<ps.size();++i) cout<<ps[i].first<<"\t"<<ps[i].second<<endl;
        return pq.top().second;
    }
    
    int get_power(int v, unordered_map<int,int> & dp) {
        if(v == 1) return 0;
        if(dp[v] != 0) return dp[v];
        int res = 0;
        if(v % 2 == 0) res = get_power(v/2, dp) + 1;
        else res = get_power(3 * v + 1, dp) + 1;
        dp[v] = res;
        return res;
    }
};
