//记录长度相等的一些单词，从start经过一个字母变换，最终变为end单词的最少步数

class Solution {
public:
    bool isEdge(string & a, string & b) {
        int count = 0;
        for(int i = 0; i < a.length(); ++i) {
            if(a[i] != b[i]) ++count;
        }
        return (count == 1);
    }
    int ladderLength(string start, string end, unordered_set<string> &dict1) {
        if(start == end) return 0;
        int n = dict1.size();
        vector<string> dict(n);
        int i = 0;
        for(auto it = dict1.begin(); it != dict1.end(); ++it) dict[i++] = *it;
        vector<vector<int>> edges(n);
        int st = 0, en = 0;
        for(int i = 0; i < n; ++i) {
            if(dict[i] == start) {
                st = i;
            }
            else if(dict[i] == end) {
                en = i;
            }
            vector<int> e;
            for(int j = 0; j < n; ++j) {
                if(isEdge(dict[i], dict[j])) e.push_back(j);
            }
            edges[i] = e;
        }
        vector<bool> isVis(n,false);
        queue<pair<int, int>> qs;
        qs.push(pair<int, int>(st,1));
        isVis[st] = true;
        while(!qs.empty()) {
            pair<int,int> pt = qs.front(); qs.pop();
            int t = pt.first;
            vector<int> e = edges[t];
            for(int i = 0; i < e.size(); ++i) {
                if(e[i] == en) return pt.second + 1;
                if(isVis[e[i]]) continue;
                isVis[e[i]] = true;
                qs.push(pair<int,int>(e[i], pt.second + 1));
            }
        }
        return 0;
    }
};
