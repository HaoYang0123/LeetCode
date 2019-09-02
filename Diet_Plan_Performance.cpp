//Leetcode 1176

class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int T=0, n=calories.size();
        for(int i=0;i<k;++i) T += calories[i];
        int res=0;
        if(T<lower) --res;
        else if(T>upper) ++res;
        for(int i=k;i<n;++i) {
            T = T+calories[i]-calories[i-k];
            if(T<lower) --res;
            else if(T>upper) ++res;
        }
        return res;
    }
};
