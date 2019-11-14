//Leetcode 410
//方法1：
//动态规划+分治+减枝，但几乎差点超时
//dp[start][end][m]表示从start至end，分割m次的结果

//方法2：
//使用二分法，结果一定在[0,INT_MAX]中，先二分出来一个值mid(INT_MAX/2)，查看能不能按照该值切割成m份
//如果切割大于m份，说明该值太小，结果一定在mid+1和right中间
//否则，结果一定在left和mid中间

//方法1：
class Solution {
public:
	int splitArray(vector<int> & nums, int m) {
		int n=nums.size();
		vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(m+1, LLONG_MAX)));
		vector<long long> cur_sum(n, 0);
		cur_sum[0] = nums[0];
		for(int i=1;i<n;++i) {
			cur_sum[i] = cur_sum[i-1] + nums[i];
		}
		for(int i=0;i<n;++i) {
			for(int j=i;j<n;++j) {
				if(i==0) dp[i][j][1] = cur_sum[j];
				else dp[i][j][1] = cur_sum[j]-cur_sum[i-1];
			}
		}
		return dfs(dp, 0, n-1, m);
	}

	long long dfs(vector<vector<vector<long long>>> & dp, int start, int end, int m) {
		if(dp[start][end][m] != LLONG_MAX) return dp[start][end][m];
		long long res = LLONG_MAX;
		for(int i=start+1;i<=end+2-m;++i) { //
			if(dp[start][i-1][1] >= res) continue;
			long long cur = max(dp[start][i-1][1], dfs(dp, i, end, m-1));
			res = min(res, cur);
		}
		dp[start][end][m] = res;
		return res;
	}
};

//方法2：
class Solution {
public:
	bool can_split(vector<int> & nums, int m, long long v) {
		int cur_split = 0; //当前切割数量
		long long cur_sum = 0;
		for(int i=0;i<nums.size();++i) {
			cur_sum += nums[i];
			if(cur_sum > v) { //如果当前group中求和>v，那么当前值nums[i]需要放到新的group
				cur_split++; //切割数量加1
				if(cur_split >= m) return false; //如果切割数量超过m，则说明使用v来切割成m份不行（需要大于m份）
				cur_sum = nums[i]; //更新当前新group的求和值
			}
		}
		return true;
	}

	int splitArray(vector<int> & nums, int m) {
		long long left = INT_MIN, right = 0;
		for(int i=0;i<nums.size();++i) {
			left = max(left, (long long)nums[i]);
			right += nums[i];
		}
		while(left < right) { //结果一定在left和right之间
			long long mid = left + (right - left) / 2; //二分
			if(can_split(nums, m, mid)) right = mid; //如果能够使用mid切割成m份，则结果在[left,mid]之间
			else left = mid + 1; //否则，结果在[mid+1,right]之间
		}
		return left;
	}
};
