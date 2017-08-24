/* 
    HDU 1950 Bridging signals 
            -----最长上升子序列nlogn算法 
*/  
  
#include<cstdio>  
#include<cstring>  
#define MAXN 40005  
  
int arr[MAXN],ans[MAXN],len;  
  
/*  
    二分查找。 注意，这个二分查找是求下界的;  (什么是下界？详情见《算法入门经典》 P145) 
    即返回 >= 所查找对象的第一个位置（想想为什么） 
 
    也可以用STL的lowe_bound二分查找求的下界 
*/  
  
int binary_search(int i){  
    int left,right,mid;  
    left=0,right=len;  
    while(left<right){  
        mid = left+(right-left)/2;  
        if(ans[mid]>=arr[i]) right=mid;  
        else left=mid+1;  
    }  
    return left;  
}  
  
int main()  
{  
    freopen("input.txt","r",stdin);  
    int T,p,i,j,k;  
    scanf("%d",&T);  
    while(T--){  
        scanf("%d",&p);  
        for(i=1; i<=p; ++i)  
            scanf("%d",&arr[i]);  
          
        ans[1] = arr[1];  
        len=1;  
        for(i=2; i<=p; ++i){  
            if(arr[i]>ans[len])  
                ans[++len]=arr[i];  
            else{  
                int pos=binary_search(i);   // 如果用STL： pos=lower_bound(ans,ans+len,arr[i])-ans;   
                ans[pos] = arr[i];  
        }  
        printf("%d\n",len);  
    }  
    return 0;  
}  
