//Leetcode 947
//相当于找Island的数目，属于同一行或同一列的则相互连通，最终结果是结点数目减去Island的数目（因为每个Island都会最终只保留一个结点）
//使用宽度搜索找连通的Island。

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> graph(n, vector<int>(n+1,0)); //graph[i][0] store the length of graph[i][1:]
        for(int i=0;i<n;++i) {
            for(int j=i+1;j<n;++j) {
                //cout<<i<<"\t"<<j<<endl;
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i][++graph[i][0]] = j;
                    graph[j][++graph[j][0]] = i;
                }
            }
        }
        //cout<<"OK"<<endl;
        int res = 0;
        vector<bool> visited(n, false);
        for(int i=0;i<n;++i) {
            if(visited[i]) continue;
            queue<int> que;
            que.push(i);
            visited[i] = true;
            --res;
            
            while(!que.empty()) {
                int c = que.front();
                que.pop();
                ++res;
                for(int j=1;j<=graph[c][0];++j) {
                    int nei = graph[c][j];
                    //cout<<nei<<endl;
                    if(visited[nei]) continue;
                    visited[nei] = true;
                    que.push(nei);
                }
            }
        }
        return res;
    }
};
