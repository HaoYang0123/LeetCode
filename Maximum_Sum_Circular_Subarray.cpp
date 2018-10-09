//Leetcode 918
//计算环状数组的最大子串和（比如[5,-2,5]的结果是10，因为最后一个元素的下一个元素是第一个元素）

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if(A.size()==0) return 0;
        int res = 0, maxRes = INT_MIN;
        for(int i=0;i<A.size();++i) {
            res+=A[i];
            if(res>maxRes) maxRes = res;
            if(res<0) {
                res = 0;
            }
        } //使用常规方式计算最大子串和，没考虑最后一个元素接第一个元素的情况（比如[5,-2,5]）
        if(maxRes<0) return maxRes;
        int maxRes2=INT_MIN,sum=0;
        res=0;
        for(int i=0;i<A.size();++i) {
            sum+=A[i];
            res+=-A[i]; //将原数组所有元素取反，再使用常规方式计算最大子串和，即计算了原数组的最小子串和（的相反数），那么原数组的最大子串和等于原数组求和+该值
            if(res>maxRes2) maxRes2=res;
            if(res<0) {
                res=0;
            }
        }
        maxRes2 = sum + maxRes2;
        if (maxRes2>maxRes) maxRes=maxRes2;
        return maxRes;
    }
};
