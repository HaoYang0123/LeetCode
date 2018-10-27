//Leetcode 703
//在数组中，动态（“动态”表示数组会实时增加新的元素）找第K大的数
//使用优先队列（可以看成是最小堆，堆一直维持K个数，堆顶存最小的数，如果新来的数比堆顶元素大，那么则更新堆）

class KthLargest {
public:
    int n;
    priority_queue<int,vector<int>,greater<int>> q;
    KthLargest(int k, vector<int> nums) {
        n=k;
        for(int i=0;i<nums.size();++i) {
            add(nums[i]);
        }
    }
    
    int add(int val) {
        if(q.size()<n) q.push(val);
        else if(q.top()<val) {
            q.pop();
            q.push(val);
        }
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
