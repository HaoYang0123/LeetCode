//Leetcode 334
//O(N)的时间复杂度，O(1)的空间复杂度

//方式1：比较复杂
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        stack<int> st; //记录当前的升序序列
        int n=nums.size();
        int second_v = INT_MAX; //记录之前清空的st中的第二个元素的值
        //注意：关键在于second_v的使用，比如样例：[1,2,0,3]
        //如果没有second_v，那么st之前维护(1,2)，当遇到0，会将前面两个元素清空，入0，最后入(0,3)
        //st的大小一直没到3，会返回false；其实存在(1,2,3)这样的解
        //所以，使用second_v保存当前为止最小的第二个元素的值，比如当st的个数为2时，则更新second_v（当st记录(1,2)时，second_v更新为2）
        for(int i=0;i<n;++i) {
            if(nums[i]>second_v) return true; //如果比第二个元素的值大，则直接返回true
            if(st.empty()) st.push(nums[i]);
            else {
                if(nums[i]>st.top()) {
                    st.push(nums[i]);
                    if(st.size() >= 3) return true; //如果st的个数等于3，则返回true
                    if(st.size() == 2) second_v = min(second_v, st.top()); //如果st的个数等于2，则更新second_v
                }
                else {
                    while(!st.empty() && st.top()>=nums[i]) st.pop(); //将st中大于等于nums[i]的出栈
                    st.push(nums[i]); //当前元素入栈
                }
            }
        }
        return false;
    }
};

//方式2：比较简单
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int num0 = INT_MAX, num1 = INT_MAX;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] <= num0) { //nums[i]比1号元素小，则nums[i]作为1号元素
                num0 = nums[i];
            }
            else if(nums[i] <= num1) { //走到else，说明nums[i]比1号元素大，且比之前的2号元素小，则更新为2号元素
                num1 = nums[i];
            }
            else { //如果nums[i]即比1号元素大又比2号元素大，则说明存在解
                return true;
            }
        }
        return false;
    }
};
