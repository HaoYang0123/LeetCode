//Leetcode 1203
//两层图的拓扑排序算法

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        unordered_set<int> group_ids;
        int neg_one_flag = 0;
        for(int i=0;i<n;++i) {
            group_ids.insert(group[i]);
            if(group[i] == -1) neg_one_flag = 1;
        }
        vector<vector<int>> out_edges(n, vector<int>()); //只考虑在同一个group下的子图
        vector<vector<int>> in_edges(n, vector<int>());
        for(int i=0;i<beforeItems.size();++i) {
            vector<int> & items = beforeItems[i];
            for(int j=0;j<items.size();++j) {
                if(group[i]==group[items[j]]) {
                    out_edges[items[j]].push_back(i);
                    in_edges[i].push_back(items[j]);
                }
            }
        }
        
        unordered_map<int, vector<int>> gid2res = tp_sort(group_ids, group, in_edges, out_edges);
        //cout<<"group num:\t"<<gid2res.size()<<"\t"<<group_ids.size()<<endl;
        if(gid2res.size() != group_ids.size() - neg_one_flag) return vector<int>();
        
        //将子图看作一个结点，生成大图
        int big_group_num = 0; //大图中结点数量
        unordered_map<int, int> newgid2oldgid, newgid2nodeid;
        unordered_map<int, int> nid2gid = get_nodeid2groupid(group, big_group_num, newgid2oldgid, newgid2nodeid);
        //for(auto ind = nid2gid.begin(); ind != nid2gid.end(); ++ind) cout<<ind->first<<"\t"<<ind->second<<endl;
        vector<vector<int>> out_edges_g(big_group_num, vector<int>());
        vector<vector<int>> in_edges_g(big_group_num, vector<int>());
        unordered_set<int> group_ids_g;
        vector<int> group_g(big_group_num, 0);
        group_ids_g.insert(0);
        //cout<<"node num in big group:\t"<<big_group_num<<endl;
        for(int i=0;i<beforeItems.size();++i) {
            vector<int> & items = beforeItems[i];
            for(int j=0;j<items.size();++j) {
                int startid = items[j], endid = i;
                if(nid2gid[startid] == nid2gid[endid]) continue; //说明在一个子图中
                out_edges_g[nid2gid[startid]].push_back(nid2gid[endid]);
                in_edges_g[nid2gid[endid]].push_back(nid2gid[startid]);
            }
        }
        unordered_map<int, vector<int>> gid2res_g = tp_sort(group_ids_g, group_g, in_edges_g, out_edges_g);
        //for(auto ind = gid2res_g.begin(); ind != gid2res_g.end(); ++ind) cout<<ind->first<<"\t"<<ind->second.size()<<endl;
        vector<int> g_res = gid2res_g[0];
        if(g_res.size() != big_group_num) return vector<int>();
        vector<int> res;
        for(int i=0;i<g_res.size();++i) {
            int gid = g_res[i];
            int old_gid = newgid2oldgid[gid];
            if(old_gid == -1) res.push_back(newgid2nodeid[gid]);
            else {
                vector<int> & one_group_res = gid2res[old_gid];
                res.insert(res.end(), one_group_res.begin(), one_group_res.end());
            }
        }
       
        return res;
    }
    
    unordered_map<int, vector<int>> tp_sort(unordered_set<int> & group_ids, vector<int> & group, vector<vector<int>> & in_edges, vector<vector<int>> & out_edges) {
        unordered_map<int, vector<int>> gid2res; //group_id对应的结果
        unordered_map<int, vector<int>> gid2nodeids; //group_id对应的结点ids
        for(int i=0;i<group.size();++i) gid2nodeids[group[i]].push_back(i);
        for(auto ind = group_ids.begin(); ind != group_ids.end(); ++ind) {
            int group_id = *ind;
            if(group_id == -1) continue;
            queue<int> zero_ins;
            unordered_map<int, int> in_degree = get_in_degree(gid2nodeids[group_id], in_edges, zero_ins);
            //cout<<group_id<<"\t"<<zero_ins.size()<<endl;
            vector<int> one_group_res;
            while(!zero_ins.empty()) {
                int node_id = zero_ins.front();
                zero_ins.pop();
                one_group_res.push_back(node_id);
                vector<int> & edges = out_edges[node_id];
                for(int k=0; k<edges.size(); ++k) {
                    --in_degree[edges[k]];
                    if(in_degree[edges[k]] == 0) zero_ins.push(edges[k]);
                }
            }
            if(one_group_res.size() != in_degree.size()) return gid2res; //说明此group有环
            gid2res[group_id] = one_group_res;
            //cout<<"====="<<group_id<<"=========="<<endl;
            //for(int k=0;k<one_group_res.size();++k) cout<<"\t"<<one_group_res[k];
            //cout<<endl;
        }
        return gid2res;
    }
    
    unordered_map<int, int> get_in_degree(vector<int> & node_ids, vector<vector<int>> & in_edges, queue<int> & zero_ins) {
        unordered_map<int, int> in;
        for(int i=0;i<node_ids.size();++i) {
            int node_id = node_ids[i];
            in[node_id] = in_edges[node_id].size();
            if(in[node_id] == 0) zero_ins.push(node_id);
        }
        return in;
    }
    
    unordered_map<int, int> get_nodeid2groupid(vector<int> & group, int & group_num, unordered_map<int, int> & newgid2oldgid, unordered_map<int, int> & newgid2nodeid) {
        int cur_gid = 0;
        unordered_map<int, int> res, gid2gid;
        for(int i=0;i<group.size();++i) {
            if(group[i] == -1) {
                res[i] = cur_gid++;
                newgid2oldgid[res[i]] = group[i];
                newgid2nodeid[res[i]] = i;
            }
            else {
                int gid = group[i];
                if(gid2gid.find(gid) == gid2gid.end()) gid2gid[gid] = cur_gid++;
                res[i] = gid2gid[gid];
                newgid2oldgid[res[i]] = gid;
                newgid2nodeid[res[i]] = i;
            }
        }
        group_num = cur_gid;
        return res;
    }
};
