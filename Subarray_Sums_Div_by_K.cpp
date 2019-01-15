//Leetcode 974
//O(NlogN)时间复杂度，利用分治法将数组等分成两份
//网上有O(N)时间复杂度的算法。在最下面。

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        return dfs(A, 0, A.size()-1, K);
    }

	int dfs(vector<int> & A, int start, int end, int K) {
		if(start > end) return 0;
		if(start==end) {
			if(A[start] % K == 0) return 1;
			return 0;
		}
		int mid = (start+end)/2;
		int left = dfs(A, start, mid, K), right = dfs(A, mid+1, end, K);
		int res = left + right;
		//vector<int> v(end - mid + 1, 0);
		unordered_map<int, int> mm; //统计从mid+1开始的求和值，余K的个数
		int tmp = 0;
		for(int i=mid+1;i<=end;++i) {
			tmp += A[i];
			mm[tmp%K]++;
		}
		tmp = 0;
		for(int i=mid;i>=start;--i) {
			tmp += A[i];
			int y = tmp % K;
			int z = 0;
			if(y>0) z = K - y; //z是[0,K)
			else if(y<0) z = -K - y; //z是[0,K)
			auto ind = mm.find(z);
			if(ind != mm.end()) res += ind->second;

			if(y!=0) {
				z = -y;
				ind = mm.find(z);
				if(ind != mm.end()) res += ind->second;
			}
		}
		return res;
	}
};

//O(N)的时间复杂度，使用sum[i]来统计从0到i的求和值，然后使用div[k]统计在sum数组中有多少个数除K等于k。
//这样：如果div[k]=4，假设这4个位置分别为x1,x2,x3,x4，那么在4个中任意选择2个（比如x2,x4），那么x2+1,..x4位置的求和(sum[x4]-sum[x2])必然等于0.
//所以最后的值等于(C(div[i],2) for i in range(0,K)）
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n = A.size();
        vector<int> sum(n+1, 0);
        vector<int> div(K, 0);
        for(int i=0;i<n;++i) sum[i+1] += sum[i]+A[i];
        for(int i=0;i<=n;++i) {
            int d = (sum[i] % K + K) % K;
            div[d]++;
        }
        int res = 0;
        for(int i=0;i<K;++i) {
            //cout<<i<<"\t"<<div[i]<<endl;
            res += (div[i] * (div[i] - 1)) / 2;
        }
        return res;
    }
};
