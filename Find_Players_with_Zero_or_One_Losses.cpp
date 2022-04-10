// Leetcode 2225

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> player2lostnum;
        for(int i=0; i<matches.size(); ++i) {
            int a = matches[i][0], b = matches[i][1];
            if(player2lostnum.find(a) == player2lostnum.end()) 
                player2lostnum[a] = 0;
            player2lostnum[b]++;
        }
        vector<int> a, b;
        for(auto idx=player2lostnum.begin(); idx!=player2lostnum.end(); ++idx) {
            if(idx->second == 0) a.push_back(idx->first);
            else if(idx->second == 1) b.push_back(idx->first);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return {a,b};
    }
};
