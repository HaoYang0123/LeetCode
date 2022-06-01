// Leetcode 2285

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> rs(n, 0);  //每个结点的入度数目，rs中的key是结点值，value中的value是结点的入度/出度
        for(int i=0; i<roads.size(); ++i) {
            int a = roads[i][0], b = roads[i][1];
            //cout<<a<<":"<<b<<endl;
            rs[a]+=1;
            rs[b]+=1;
        }
        map<int, vector<int>> mm;  //按照结点的入度/出度，从小到大排序
        for(int i=0; i<n; ++i) {
            mm[rs[i]].push_back(i);
        }
        int cur = 1;
        vector<int> nodes(n, 0);
        for(auto idx=mm.begin(); idx!=mm.end(); ++idx) {  //从小到大排序
            vector<int> & s_nodes = idx->second;
            for(int i=0; i<s_nodes.size(); ++i) {
                nodes[s_nodes[i]] = cur++;
            }
        }
        long long res = 0;
        for(int i=0; i<roads.size(); ++i) {
            int a = roads[i][0], b = roads[i][1];
            res += (long long)(nodes[a]) + (long long)(nodes[b]);
        }
        return res;
    }
};
