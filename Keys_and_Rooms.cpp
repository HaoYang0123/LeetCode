//Leetcode 841
//判断图是否是全连接图，使用宽度优先搜索（使用队列来访问图中节点）

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> qs;
        vector<int> is_visited(n+1,0);
        is_visited[0] = 1;
        qs.push(0);
        int r = 1;
        while(!qs.empty()) {
            int index = qs.front();
            qs.pop();
            vector<int> keys = rooms[index];
            for(int i=0;i<keys.size();++i) {
                if(is_visited[keys[i]]) continue;
                ++r;
                is_visited[keys[i]] = 1;
                qs.push(keys[i]);
            }
        }
        return (r==n);
    }
};
