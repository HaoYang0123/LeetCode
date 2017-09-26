//Leetcode 636
//有n个函数，记录每个函数的start或者end时间，通过如下方式：函数ID：start/end：时间
//["0:start:0",
// "1:start:2",
// "1:end:5",
// "0:end:6"]
//Output:[3, 4]
//认为函数0从0秒开始运行，到2秒函数1开始运行，所以函数0会运行2秒(2-0)，后续函数1从2秒运行到5秒结束（这里end:5表示5秒末尾结束，即运行了6-2=4秒），后续函数0又从末尾5运行到末尾6，又运行了1秒
//所以最终是函数0运行了3秒(2+1)，函数1运行了4秒

class Solution {
public:
    void parse(string & l, int & funId, bool & start, int & value) {
        pair<int, int> res;
        auto ind = l.find(':');
        funId = atoi(l.substr(0, ind).c_str());
        l = l.substr(ind + 1);
        ind = l.find(':');
        value = atoi(l.substr(ind + 1).c_str());
        string flag = l.substr(0, ind);
        if(flag == "start") start = true;
        else if(flag == "end") start = false;
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> s; //使用栈来存储当前运行的函数
        int prevTime = 0;
        for(int i = 0; i < logs.size(); ++i) {
            int time = 0, funId = 0;
            bool start = true;
            parse(logs[i], funId, start, time);
            if(!s.empty()) res[s.top()] += time - prevTime;
            prevTime = time;
            if(start) s.push(funId);
            else {
                res[s.top()]++;
                s.pop();
                prevTime++;
            }
        }
        return res;
    }
};
