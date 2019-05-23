// Leetcode 1046

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        while(stones.size() >= 2) {
            int a=stones.back();
            stones.pop_back(); //删除最后一个元素
            int b=stones.back();
            stones.pop_back();
            if (a==b) continue; //两个同时消失
            if(stones.size() == 0) return a-b;
            int c=a-b; //将c插入到有序的数组中
            auto ind = lower_bound(stones.begin(), stones.end(), c); //在stones数组中找第一个>=c的元素
            if(ind == stones.end()) stones.push_back(c); //没找到
            else {
                stones.insert(ind, c);
            }
        }
        if(stones.size()==0) return 0;
        return stones[0];
    }
};
