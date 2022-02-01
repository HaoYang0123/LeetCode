// Leetcode 2059

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        if(start == goal) return 0;
        vector<bool> is_vis(1002, false);  //因为只有到达[0,1000]才可以继续走下一步；如果超过此范围那么直接就终止了
        queue<pair<int, int>> qs;  //使用BFS搜索
        qs.push({start, 0});
        is_vis[start] = true;
        while(!qs.empty()) {
            pair<int, int> cur = qs.front();
            //cout<<cur.first<<":"<<cur.second<<endl;
            qs.pop();
            for(int i=0; i<nums.size(); ++i) {
                int newv = cur.first + nums[i];
                int newv2 = cur.first - nums[i];
                int newv3 = cur.first ^ nums[i];
                if(newv == goal || newv2 == goal || newv3 == goal) return cur.second+1;
                if(newv >= 0&& newv <= 1000 && !is_vis[newv]) {
                    is_vis[newv] = true;
                    qs.push({newv, cur.second+1});
                }
                if(newv2 >= 0 && newv2 <= 1000 && !is_vis[newv2]) {
                    is_vis[newv2] = true;
                    qs.push({newv2, cur.second+1});
                }
                if(newv3 >= 0 && newv3 <= 1000 && !is_vis[newv3]) {
                    is_vis[newv3] = true;
                    qs.push({newv3, cur.second+1});
                }
            }
        }
        return -1;
    }
};
