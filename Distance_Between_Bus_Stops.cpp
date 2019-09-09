//Leetcode 1184

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int sum = 0, cur = 0;
        int n = distance.size();
        if(start > destination) {
            int tmp=start;
            start = destination;
            destination=tmp;
        }
        for(int i=0;i<n;++i) {
            sum += distance[i];
            if(i>=start && i<destination) cur += distance[i];
        }
        return min(cur, sum-cur);
    }
};
