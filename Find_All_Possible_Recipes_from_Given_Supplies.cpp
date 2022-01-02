// Leetcode 2115

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> has_sup;
        for(int i=0; i<supplies.size(); ++i) has_sup.insert(supplies[i]);
        int n=recipes.size();
        vector<bool> is_vis(n, false);
        queue<int> qs; //目前还需要的recipes，还没有加进来的recipes
        for(int i=0;i<n;++i) qs.push(i);
        bool need_itr = true;
        while(need_itr) {
            need_itr = false;
            queue<int> qs_tmp;
            while(!qs.empty()) {
                int ri = qs.front();
                qs.pop();
                vector<string> & ing = ingredients[ri];
                bool is_ok = true;
                for(int i=0; i<ing.size(); ++i) {
                    if(has_sup.find(ing[i]) == has_sup.end()) {  //没有对应的原材料，就表示此recipes当前还不能做
                        is_ok = false;
                        break;
                    }
                }
                if(is_ok) {
                    is_vis[ri] = true;
                    has_sup.insert(recipes[ri]);
                    need_itr = true;  //表示还有需要做的
                }
                else {
                    qs_tmp.push(ri);
                }
            }
            qs = qs_tmp;
        }
        vector<string> res;
        for(int i=0; i<n; ++i) {
            if(is_vis[i]) res.push_back(recipes[i]);
        }
        return res;
    }
};
