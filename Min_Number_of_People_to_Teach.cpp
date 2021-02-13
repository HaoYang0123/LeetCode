// Leetcode 1733

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size(); // m个用户
        vector<unordered_set<int>> lang; //lang[i]表示第i个用户会的语言
        for(int i=0;i<m;++i) {
            unordered_set<int> tmp;
            for(int j=0;j<languages[i].size();++j) tmp.insert(languages[i][j]);
            lang.push_back(tmp);
        }
        vector<pair<int,int>> edges; //找到一些目前无法共享语言的用户边
        for(int i=0;i<friendships.size();++i) {
            int a = friendships[i][0], b = friendships[i][1];
            unordered_set<int> & la = lang[a-1];
            unordered_set<int> & lb = lang[b-1];
            if(!can_communicate(la, lb)) edges.push_back(pair<int,int>(a-1, b-1));
        }
        int res = INT_MAX;
        for(int i=1; i<=n; ++i) { //枚举教第i种语言，需要教多少个用户
            unordered_set<int> need_teach; // 需要教用户的集合
            for(int j=0; j<edges.size(); ++j) {
                int a = edges[j].first, b = edges[j].second;
                unordered_set<int> & la = lang[a];
                unordered_set<int> & lb = lang[b];
                if(la.find(i) == la.end()) need_teach.insert(a); //因为a用户不会第i种语言，所以需要将a用户加入至need_teach中
                if(lb.find(i) == lb.end()) need_teach.insert(b); //同理，b用户不会则也加入其中
            }
            res = min(res, int(need_teach.size())); //答案是最小的教的用户数量
        }
        return res;
    }
    
    inline bool can_communicate(unordered_set<int> a, unordered_set<int> b) {
        for(auto ind = a.begin(); ind != a.end(); ++ind) {
            if(b.find(*ind) != b.end()) return true;
        }
        return false;
    }
};
