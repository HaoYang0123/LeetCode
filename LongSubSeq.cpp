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
