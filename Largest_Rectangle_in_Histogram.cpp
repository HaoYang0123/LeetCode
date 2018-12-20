//Leetcode 84
//计算最大面积
//维护一个升序的栈，比如[1,3,4,9]，那么最大面积必然是[1*4,3*3,4*2,9*1]中选择。
//对于非升序的数组，比如：[2,1,5,6,2,3]，如果遇到当前元素比栈的最顶元素（最大元素）小，那么就将所有大于当前元素的值弹出，并计算最大面积
//将弹出的元素重新用当前元素值插入到栈中
//比如{2},当遇到下一个元素1时，将2弹出（计算最大面积为2*1=2），并将1插入其中得到{1,1}，后面将5，6插入得到{1,1,5,6}
//下一个元素为2，那么5和6均要弹出，并从5*2和6*1得到最大面积（面积为10）。将弹出的5和6两个元素以当前元素（2）重新插入栈中
//得到{1,1,2,2,2}，最后将3插入栈中得到{1,1,2,2,2,3}。在此栈中计算最大面积[1*6,1*5,2*4,2*3,2*2,3*1]
//最终最大面积为5*2=10

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0) return 0;
        stack<int> sta;
        sta.push(heights[0]);
        int res=0;
        for(int i=1;i<heights.size();++i) {
            if(heights[i]>=sta.top()) sta.push(heights[i]);
            else {
                int n = sta.size();
                int width = 1;
                while(!sta.empty()) {
                    if(sta.top()<=heights[i]) break;
                    int c = sta.top();
                    sta.pop();
                    int tmp = c*width;
                    if(tmp>res) res = tmp;
                    ++width;
                }
                while(sta.size()<=n) sta.push(heights[i]);
            }
        }
        int width = 1;
        while(!sta.empty()) {
            int c = sta.top();
            sta.pop();
            int tmp = c*width;
            if(tmp>res) res = tmp;
            ++width;
        }
        return res;
    }
};
