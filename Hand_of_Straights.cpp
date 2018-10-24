//Leetcode 846
//穷举法

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        unordered_map<int,int> map;
        int n=hand.size();
        if(n%W != 0) return false;
        sort(hand.begin(), hand.end());
        for(int i=0;i<n;++i) {
            auto ind = map.find(hand[i]);
            if(ind == map.end()) map[hand[i]] = 1;
            else map[hand[i]] += 1;
        }
        for(int i=0;i<n;++i) {
            while(i<n&&map[hand[i]] == 0) ++i;
            if(i>=n) break;
            map[hand[i]]--;
            for(int j=1;j<W;++j) {
                int v = hand[i] + j;
                if(map[v] == 0) return false;
                map[v]--;
            }
        }
        return true;
    }
};
