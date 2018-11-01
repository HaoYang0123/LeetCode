//Leetcode 813
//动态规划，复杂度N^2*K

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n=A.size();
		vector<double> P(n+1,0.0);
        for(int i=0;i<n;++i) P[i+1]=P[i]+A[i];
        vector<double> dp(n,0.0); //dp[i]表示为从[i,:]切割任意次(<=K次)的最大值
        for(int i=0;i<n;++i) dp[i]=(P[n]-P[i])/(n-i);
        for(int k=0;k<K-1;++k) {
            for(int i=0;i<n;++i) {
                for(int j=i+1;j<n;++j) {
                    double tmp=(P[j]-P[i])/(j-i)+dp[j]; //[i,j)
                    if(tmp>dp[i])
                        dp[i]=tmp;
                }
            }
        }
        return dp[0];
    }
    //请忽略下面的函数，下面的函数动态规划复杂度N^3*K
	double dfs(vector<int>&A,int start,int end,int k, vector<vector<vector<double>>> & dp) { 
        //cout<<start<<"\t"<<end<<"\t"<<k<<"\t"<<dp[start][end][k]<<endl;
		if(start==end) {
			return A[start]*1.0;
		}
		if(dp[start][end][k] != 0) return dp[start][end][k];
		if(k==1) {
			double res=0.0;
			for(int i=start;i<=end;++i) {
				res+=A[i];
			}
			res/=(end-start+1);
			dp[start][end][k]=res;
			return res;
		}
		double res = 0.0;
		for(int i=start;i<end;++i) { //start,i;;;;;i+1,end
			for(int j=1;j<=i-start+1&&k-j>0;++j) {
				double a=dfs(A,start,i,j,dp);
				double b=dfs(A,i+1,end,k-j,dp);
                //cout<<start<<"\t"<<i<<"\t"<<end<<"\t"<<a<<"\t"<<b<<endl;
				if(a+b>res) res=a+b;
			}
		}
		dp[start][end][k]=res;
		return res;
	}
};
