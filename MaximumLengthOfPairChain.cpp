class Solution {public:    int findMedian(vector<vector<int>> & pairs, int pos, int target) {        int start = pos + 1, end = pairs.size() - 1, mid = 0;        while(start <= end) {            mid = start + (end - start) / 2;            //cout<<start<<"\t"<<end<<endl;            if(pairs[mid][0] > target) end = mid - 1;            else if(pairs[mid][0] < target) start = mid + 1;            else break;        }        //cout<<pos<<"\t"<<start<<endl;        int i = start - 1;        if(i <= pos) i = pos + 1;        for(; i < pairs.size(); ++i) {            if(pairs[i][0] > target) return i;        }        return pairs.size();    }        int dfs(vector<int> & edges, vector<int> & dp, int index) {        if(index >= edges.size()) {            return 0;        }         if(dp[index] != 0) return dp[index];        int pos = edges[index];        if(pos >= edges.size()) {            return 1;        }        int max = 0;        for(int i = pos; i < edges.size(); ++i) {            int tmp = dfs(edges, dp, i);            if(tmp > max) max = tmp;        }        dp[index] = max + 1;        return dp[index];    }        int findLongestChain(vector<vector<int>>& pairs) {        sort(pairs.begin(), pairs.end(), [](const vector<int> & a, const vector<int> & b){              return a[0] < b[0];        });                vector<int> edges(pairs.size()), dp(pairs.size(), 0);        for(int i = 0; i < pairs.size(); ++i) {            edges[i] = findMedian(pairs, i, pairs[i][1]);        }        int res = 0;        for(int i = 0; i < edges.size(); ++i) {            int tmp = dfs(edges, dp, i);            if(tmp > res) res = tmp;        }        /**/        return res;    }};