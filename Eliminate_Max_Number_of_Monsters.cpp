// Leetcode 1921

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<float> times;
        for(int i=0; i<dist.size(); ++i) {
            times.push_back(dist[i]*1.0/speed[i]);
        }
        sort(times.begin(), times.end());
        int cnt = 0;
        int i=1;
        for(; i < times.size(); ++i)
            if(times[i] <= i)
                break;
        
        return cnt + i;
    }
};
