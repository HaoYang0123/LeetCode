//Leetcode 833

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int n = indexes.size();
        int l = S.length();
        unordered_map<int,int> mm;
        for(int i=0;i<n;++i) mm[indexes[i]] = i;
        vector<bool> is_ori(l, true);
        unordered_map<int, string> tar;
        for(int i=0;i<l;++i) {
            if(!is_ori[i]) continue;
            auto ind = mm.find(i);
            if(ind == mm.end()) continue;
            int index = ind->second;
            if(!in_S(S, i, sources[index])) continue;
            for(int j=0;j<sources[index].length();++j) is_ori[i+j] = false;
            tar[i] = targets[index];
        }
        string res = "";
        for(int i=0;i<l;++i) {
            if(is_ori[i]) res += S[i];
            else res += tar[i];
        }
        return res;
    }
    
    bool in_S(string & S, int start, string & sou) {
        if(start + sou.length() > S.length()) return false;
        for(int l=0;l<sou.length();++l) {
            if(S[start+l] != sou[l]) return false;
        }
        return true;
    }
};
