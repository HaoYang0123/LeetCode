// Leetcode 2003
//如果基因不包含1，那么答案全部为1，直接返回
//否则基因中包含了1，那么找到基因等于1的结点，从根到达该结点的路径上的所有结点的答案均不为1（因为1在里面了），其余结点的答案均为1
//对于在路径上的结点，需要重新计算，使用DFS深度搜索计算即可，注：先将基因等于1的结点进行深度搜索得到该子树的集合情况，然后依次往上计算即可

class Solution {
public:
    vector<bool> num_vis;
    vector<bool> is_vis;
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n=parents.size();
        num_vis.resize(100001, false);
        is_vis.resize(n, false);
        vector<int> res(n, 1);
        int min_n = INT_MAX, min_1_idx = -1;
        for(int i=0; i<n; ++i) {
            min_n = min(min_n, nums[i]);
            if(nums[i] == 1) min_1_idx = i;
        }
        if(min_n > 1) return res;
        vector<int> path;
        int cur = min_1_idx;
        while(cur != -1) {
            path.push_back(cur);
            cur = parents[cur];  //找到1向上的路径，这几个数据的缺失最小基因值需要重新计算，因为包含了1
        }
        //构建图
        vector<vector<int>> edges(n);
        int root_idx = -1;
        for(int i=0; i<n; ++i) {
            int pare = parents[i];
            if(pare != -1) {
                edges[pare].push_back(i);
            }
            else {
                root_idx = i;
            }
        }
        //cout<<"path\t"<<path.size()<<endl;
        int cur_n = 2;
        for(int i=0; i<path.size(); ++i) {
            int node = path[i];
            //cout<<"node\t"<<node<<endl;
            get_all_nums(node, nums, edges);
            //cout<<node<<endl;
            while(num_vis[cur_n]) ++cur_n;
            res[node] = cur_n;
        }
        return res;
    }

    void get_all_nums(int root, vector<int> & nums, vector<vector<int>> & edges) {
        if(is_vis[root]) return;
        num_vis[nums[root]] = true;
        vector<int> to_nodes = edges[root];
        if(to_nodes.size() == 0) {  //叶子结点
            return;
        }
        for(int i=0; i<to_nodes.size(); ++i) {
            get_all_nums(to_nodes[i], nums, edges);
        }
        is_vis[root] = true;
    }
};
