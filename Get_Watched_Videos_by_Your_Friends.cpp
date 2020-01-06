//Leetcode 1311
//宽度优先搜索

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = watchedVideos.size();
        queue<pair<int,int>> qs; //pair<int,int>表示到达的id号，及对应的level(路径最小步数)
        vector<bool> is_vis(n, false);
        is_vis[id] = true;
        qs.push(pair<int,int>(id, 0));
        vector<int> level_fri;
        while(!qs.empty()) {
            pair<int,int> cur = qs.front();
            qs.pop();
            if(cur.second == level) level_fri.push_back(cur.first);
            if(cur.second > level) break;
            vector<int> & fri = friends[cur.first];
            for(int i=0;i<fri.size();++i) {
                if(is_vis[fri[i]]) continue;
                is_vis[fri[i]] = true;
                qs.push(pair<int,int>(fri[i], cur.second+1));
            }
        }
        //for(int i=0;i<level_fri.size();++i) cout<<level_fri[i]<<endl;
        unordered_map<string, int> video2num;
        for(int i=0;i<level_fri.size();++i) {
            int fri_index = level_fri[i];
            vector<string> & wv = watchedVideos[fri_index];
            for(int j=0;j<wv.size();++j) {
                video2num[wv[j]]++;
            }
        }
        vector<pair<string,int>> tmp;
        for(auto ind = video2num.begin(); ind != video2num.end(); ++ind) {
            tmp.push_back(pair<string,int>(ind->first, ind->second));
        }
        sort(tmp.begin(), tmp.end(), [=](pair<string, int>& a, pair<string, int>& b) {
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second; 
        });
        vector<string> res(tmp.size());
        for(int i=0; i<res.size(); ++i) res[i] = tmp[i].first;
        return res;
    }
};
