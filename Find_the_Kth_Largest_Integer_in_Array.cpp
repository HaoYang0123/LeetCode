// Leetcode 1985
//优先队列

class Solution {
public:
    
    struct cmp {
        bool operator()(const string & a, const string & b) {
            //a>b, 从小到大，队头最小
            if(a.length() > b.length()) return true;
            else if(a.length() == b.length()) return a > b;
            return false;
        }
    };
    
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, cmp> pq;
        for(int i=0; i<nums.size(); ++i) pq.push(nums[i]);
        while(pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
};
