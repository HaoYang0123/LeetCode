//Leetcode 1496

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> is_visited;
        is_visited.insert("0@0");
        int cur_i = 0, cur_j = 0;
        for(int i=0; i<path.length(); ++i) {
            if(path[i] == 'N') ++cur_i;
            else if(path[i] == 'S') --cur_i;
            else if(path[i] == 'E') ++cur_j;
            else --cur_j;
            string key = to_string(cur_i) + "@" + to_string(cur_j);
            if(is_visited.find(key) != is_visited.end()) return true;
            is_visited.insert(key);
        }
        return false;
    }
};
