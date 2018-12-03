//Leetcode 904
//O(n)时间复杂度

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int i=0,j=0,oldJ=0;
        int v=tree[0];
        int res=0;
        int a=v, b=-1;
        for(int k=1;k<tree.size();++k) {
            if(tree[k] != tree[k-1]) {
                oldJ=j;
                j=k;
                if (b==-1) b=tree[k];
                else {
                    if(a!=tree[k] && b!=tree[k]) {
                        int cur = k-i;
                        if(cur>res) res = cur;
                        i=oldJ;
                        a=tree[oldJ];
                        b=tree[k];
                    }
                }
            }
        }
        int cur = tree.size()-i;
        if(cur>res) res = cur;
        return res;
    }
};
