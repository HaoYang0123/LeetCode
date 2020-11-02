//Leetcode 1642
//贪心算法，用ladder_set保留当前最大的gap，如果下一个gap比当前ladder_set最小值小，那么用砖头进行填充（贪心思路）；
//如果下一个gap比当前ladder_set最小值要大，那么需要与ladder_set最小值进行替换
//上面的意思就是：由于下一个gap比较大，不合适用砖头，太浪费砖头了，需要把ladder_set最小值用砖头填充，而下一个gap用梯子

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        set<int> ladder_set;
        int i=0;
        for(;i<heights.size()-1;++i) {
            if(heights[i] < heights[i+1]) {
                int delta = heights[i+1] - heights[i];
                if(ladder_set.size() < ladders) {
                    ladder_set.insert(delta);
                }
                else {
                    int min_l = INT_MAX;
                    if (ladder_set.size() > 0) min_l = *ladder_set.begin();
                    if(min_l >= delta) { //delta非常小，那么（贪心）用砖头填充比较划算
                        if(delta > bricks) break; //如果目前剩余的砖头，已经不够用了，说明已经爬不上去了
                        else bricks -= delta; //使用砖头进行填充
                    }
                    else { //delta比较大，那么不适合用砖头填充，应该将当前ladder_set中最小的弹出，将当前的delta放进去
                        ladder_set.erase(ladder_set.begin()); 
                        ladder_set.insert(delta);
                        delta = min_l;
                        if(delta > bricks) break;
                        else bricks -= delta;
                    }
                }
            }
        }
        return i;
    }
};
