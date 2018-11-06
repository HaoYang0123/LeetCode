//Leetcode 785
//判断图是否是二分图

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> is_visited(n+1,false);
        unordered_map<int,bool> one, two;
        int start = 0;
        is_visited[0] = true;
        one[0] = true;
        bool flag = true; //true means into 1, false means into 0
        vector<int> edges = graph[start];
        //cout<<edges.size()<<endl;
        while(true) {
          vector<int> new_edges;
          for(int i=0;i<edges.size();++i) {
            int e = edges[i];
            //if(is_visited[edges[i]]) continue;
            if(flag) {
              if(one.find(e) != one.end()) return false;
              two[e] = true;
            }
            else {
              if(two.find(e) != two.end()) return false;
              one[e] = true;
            }
            if(!is_visited[e]) {
              is_visited[e] = true;
              new_edges.insert(new_edges.end(), graph[e].begin(), graph[e].end());
            }
          }
          flag = (flag ? false : true);
          while (new_edges.size() == 0) {
            bool has_no_visited = false;
            for(int i=0;i<n;++i) {
              if(!is_visited[i]) {
                has_no_visited = true;
                is_visited[i] = true;
                flag = true;
                one[i] = true;
                new_edges = graph[i];
                break;
              }
            }
            if(!has_no_visited) break;
          }
          if(new_edges.size() == 0) break;
          edges = new_edges;
        }
        return true;
    }
};
