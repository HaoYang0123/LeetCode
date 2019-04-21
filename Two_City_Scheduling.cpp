//Leetcode 1029
//类似贪心的思路，2*n个元素，每个元素2个值，将n个放入到A桶中，另外n个放入到B桶中。使得A+B的求和最小。
//贪心：将2个元素中最小值放入到对应桶中。如果A桶元素个数与B桶元素个数相等，直接返回
//否则，将元素个数大的桶，按差值从小到大排序，把对应元素从A桶取出，并将另一个元素放到B桶中

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int res=0;
        vector<int> A, B;
        int n=costs.size();
        for(int i=0;i<n;++i) {
            int tmp=min(costs[i][0],costs[i][1]);
            res += tmp;
            if(costs[i][0]<costs[i][1]) A.push_back(costs[i][1]-costs[i][0]);
            else B.push_back(costs[i][0]-costs[i][1]);
        }
        //cout<<n<<"\t"<<A.size()<<"\t"<<B.size()<<endl;
        if(A.size()==B.size()) return res;
        if(A.size()>B.size()) {
            sort(A.begin(),A.end());
            int need_num=(A.size()-B.size())/2;
            for(int i=0;i<need_num;++i) {
                res += A[i];
            }
            return res;
        }
        sort(B.begin(), B.end());
        int need_num=(B.size()-A.size())/2;
        for(int i=0;i<need_num;++i) {
            res += B[i];
        }
        return res;
    }
};
