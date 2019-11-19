//Leetcode 209
//O(N)时间复杂度

//方法1：使用start和end来记录当前窗口的情况
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0, end = 0;
        int res = INT_MAX, sum = 0; //记录从start至end窗口下的求和为sum
        while(start < nums.size() && end < nums.size()) {
            while(end < nums.size() && sum < s) { //sum<s，则可以end++
                sum += nums[end];
                ++end;
            }
            while(start < end && sum >= s) { //sum>=s时，则要start++，在窗口内找到一个最小的窗口>=sum
                if(end - start < res) res = end - start;
                sum -= nums[start];
                ++start;
            }
        }
        if(res == INT_MAX) res = 0;
        return res;
    }
};

//方法2：使用queue来记录当前窗口的值
class Solution {
public:
	int minSubArrayLen(int s, vector<int> & nums) {
		queue<int> qs;
		int cur = 0, res = INT_MAX; //记录当前在queue中的求和为cur
		for(int i=0;i<nums.size();++i) {
			qs.push(nums[i]);
			cur += nums[i];
			while(cur >= s) { //如果queue求和>=s
				int front_value = qs.front();
				qs.pop();
				cur -= front_value; //将queue中最早的元素退出（相当于方法1中的++start）
				res = min(res, int(qs.size()) + 1); //注：这里是qs.size()+1，因为qs当前求和已经小于s了，+1确保qs求和是>=s的
			}
		}
		if(res == INT_MAX) return 0;
		return res;
	}
};
