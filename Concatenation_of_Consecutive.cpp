//Leetcode 1680

class Solution {
public:
    int find(int n) //计算n的二进制数有多少位
    {
        int count=0;
        while(n>0)
        {
            count++;
            n=n/2;
        }
        return count;
    }
    int concatenatedBinary(int n) 
    {
        int m=1e9+7;
        long long ans=1;
        for(int i=2;i<=n;i++)
        {
            int bit=find(i);
            //cout<<i<<"\t"<<bit<<endl;
            ans=((ans<<bit)%m+i)%m;
        }
        return ans%m;
    }
};
