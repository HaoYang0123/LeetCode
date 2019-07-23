//Leetcode 1128

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int> mm; //mm[key]记录key值的次数
        int n=dominoes.size();
        for(int i=0;i<n;++i) {
            int a=dominoes[i][0],b=dominoes[i][1];
            if(a>b) {
                int t=a;
                a=b;
                b=t;
            }
            int key=a*10+b;
            mm[key]++;
        }
        int res=0;
        for(auto ind=mm.begin();ind!=mm.end();++ind) {
            if(ind->second==1) continue;
            int v=ind->second;
            res += (v*(v-1))/2; //值相同的数目为v，相同的pair数据就是C(v,2)
        }
        return res;
    }
};
