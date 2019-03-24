//Leetcode 795
//O(N)的时间复杂度，比如：2,3,2,1,0,3,2,4（L=2，R=3）
//使用add=1及minus=1去更新res，如果数组中当前元素在L-R之间，那么res+=add，且++add，表示以当前元素结尾的子数组的个数
//如果当前元素小于L，则说明以当前元素结尾的个数需要减去连续小于L的个数，即res-=minus，且更新++minus
//如果当前元素大于R，则更新add=1，minus=1
//其实add表示连续的<=R的元素个数，而minus表示连续的<L的元素个数
//比如上面的例子：2,3,2,1,0,3,2,4，res=0,add=1,minus=1
//遇到第1个数2，那么res=1,add=2,minus=1（res=1相当于只有"2")
//遇到第2个数3，res=3,add=3,minus=1（res=3相当于有"2","2,3","3"）
//遇到第3个数2，res=6,add=4,minus=1（res=6相当于有"2","2,3","3","2,3,2","3,2","2"）
//遇到第4个数1，res=6+add-minus=9，add=5,minus=2（本来以"1"结尾的子数组存在4个，但由于1自己是小于L，所以的减去minus）
//后面依次推导即可

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int res=0;
        int add=1,minus=1;
        for(int i=0;i<A.size();++i) {
            if(A[i]>=L&&A[i]<=R) {
                res += add;
                add++;
                minus = 1;
            }
            else if(A[i] < L) {
                res += add;
                add++;
                res -= minus;
                minus++;
            }
            else {
                add=1;
                minus=1;
            }
        }
        return res;
    }
};
