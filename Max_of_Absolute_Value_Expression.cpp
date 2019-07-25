//Leetcode 1131
//O(N)的时间复杂度
//计算：|arr1[i]-arr1[j]+|arr2[i]-arr2[j]|+|i-j|
//可以枚举绝对值的情况（将i-j直接转为i-j，默认i>j）
//则有四种情况：
//情况1：arr1[i]-arr1[j]+arr2[i]-arr2[j]，可以转化为(arr1[i]+arr2[i])-(arr1[j]+arr2[j])，则认为是一个新数组A[i]=arr1[i]+arr2[i]，计算A[i]-A[j]（i>j）最大的值
//情况2：arr1[i]-arr1[j]-arr2[i]+arr2[j]，同样如此；其它情况也是如此

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        vector<int> a1(n,0), a2(n,0), a3(n,0), a4(n,0);
        for(int i=0;i<n;++i) {
            a1[i]=arr1[i]+arr2[i]+i;
            a2[i]=arr1[i]-arr2[i]+i;
            a3[i]=-arr1[i]+arr2[i]+i;
            a4[i]=-arr1[i]-arr2[i]+i;
        }
        int v1=get_max(a1),v2=get_max(a2),v3=get_max(a3),v4=get_max(a4);
        int res=max(v1,max(v2,max(v3,v4)));
        return res;
    }
    
    int get_max(vector<int> & a) {
        int min_v=a[0];
        int res=INT_MIN;
        for(int i=1;i<a.size();++i) {
            int cur=(a[i]-min_v);
            res=max(res, cur);
            min_v=min(min_v,a[i]);
        }
        return res;
    }
};
