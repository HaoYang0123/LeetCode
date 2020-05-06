//Leetcode 1436

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> from_city, all_city;
        for(int i=0;i<paths.size();++i) {
            from_city.insert(paths[i][0]);
            all_city.insert(paths[i][0]);
            all_city.insert(paths[i][1]);
        }
        for(auto ind = all_city.begin(); ind != all_city.end(); ++ind) {
            if(from_city.find(*ind) == from_city.end()) return *ind;
        }
        return "";
    }
};
