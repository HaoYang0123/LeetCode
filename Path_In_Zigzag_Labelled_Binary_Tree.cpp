//Leetcode 1104
//比如：label=14，14->7->3->1，总共4层，第1层是正，第2层是反，第3层是正，第4层是反
//所以label=14在第4层（是反的），所以正过来14对应于9的位置；所以需要更新label=9
//从9重新得到的数组为: 9->4->2->1，然后对数组反转: 1->2->4->9，对于偶数层再反转一次（因为偶数层的顺序是反的）
//最终得到1->3->4->14
//同样，另一个例子label=26：26->13->6->3->1，由于总共5层，最后一层（第5层）是正的，所以不用将label=26更新
//反转数组: 1->3->6->13->26，对于偶数层反转，得到：1->2->6->10->26

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int floor=1;
        int old_label=label;
        int floor_num=0;
        while(label>0) {
            ++floor_num;
            label /= 2;
        }
        if(floor_num%2 == 0) { //如果最后一个数在偶数层，那么这个数本来就已经反转，所以需要对label进行反转
            int floor_min = 1;
            for(int i=1;i<floor_num;++i) floor_min *= 2;
            int floor_max = 2*floor_min;
            label = (floor_max-1-old_label+floor_min); //反转：根据当前层的最大值与最小值，及label值进行更新
        }
        else label = old_label;
        vector<int> res;
        while(label>0) {
            res.push_back(label);
            label /= 2;
        }
        reverse(res.begin(), res.end());
        //for(int i=0;i<res.size();++i) cout<<res[i]<<endl;
        int floor_max = 4, floor_min = 2; //当前层的最小值和最大值
        for(int i=1;i<res.size();i+=2) { //偶数层需要反转
            res[i]=(floor_max-1-res[i]+floor_min);
            floor_min*=4;
            floor_max*=4;
        }
        return res;
    }
};
