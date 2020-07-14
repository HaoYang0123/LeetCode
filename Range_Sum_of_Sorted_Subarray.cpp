//Leetcode 1508

//方法1：自己写的，时间有些慢，虽然时间复杂度都是O(N^2)，但我这个方法比较暴力
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> new_nums(n*(n+1)/2, 0);
        int k=0;
        for(int i=0;i<n;++i) {
            int sum = 0;
            for(int j=i;j<n;++j) {
                sum += nums[j];
                new_nums[k++] = sum;
            }
        }
        sort(new_nums.begin(), new_nums.end());
        int res = 0;
        for(int i=left-1;i<right;++i) res += new_nums[i];
        return res;
    }
};

//方法2：从网上找到的方法，使用优先队列，最开始新序列的第1个元素（从小到大排序后）一定是原数组中nums[0,...,n]的最小的一个
//假设第1个是nums[i]，那么就更新优先队列将nums[i]+nums[i+1]加入进去，再比较nums[0],..,nums[i-1],(nums[i]+nums[i+1]),nums[i+1],...中的最小的一个
//优先队列的元素数量总是维持在n个元素，只是每次都得记录nums[i...j]和j的位置，这样方便下次将nums[j+1]加入进去

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> qs;
        //使用优先队列来存储，这样所有元素（总数为n*(n+1)/2）均考虑进去，最小的元素肯定来自于nums[0...n]中最小的一个
        for(int i=0;i<n;++i) qs.push({nums[i], i+1});
        int res = 0;
        for(int i=1;i<=right;++i) {
            pair<int,int> cur = qs.top(); //最小的值拿出来
            qs.pop();
            if(i>=left) res += cur.first;
            if(cur.second < n) {
                cur.first += nums[cur.second++]; //如果最小值来自于cur，那么就要更新second的位置
                qs.push(cur);
            }
        }
        return res;
    }
};
