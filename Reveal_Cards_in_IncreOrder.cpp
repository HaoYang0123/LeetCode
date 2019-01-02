//Leetcode 950
//数组先从小到排序，最小的元素放在第1个位置，次小的放在第3个位置，次次小的放在第5个位置，...（依次类推，下一个位置放在上一个位置的后两位，注意是两个空位）

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n = deck.size();
        if(n==0) return vector<int>();
        vector<int> res(n, 0);
        vector<bool> is_visited(n, false);
        res[0] = deck[0];
        int s = 0;
        is_visited[0] = true;
        for(int i=1;i<n-1;++i) {
            int c = 0;
            while(c<2) {
                ++s;
                s %= n;
                if(!is_visited[s]) {
                    ++c;
                }
            }
            res[s] = deck[i];
            is_visited[s] = true;
        }
        s = 0;
        while(s < n && is_visited[s]) ++s;
        res[s] = deck[n-1];
        return res;
    }
};
