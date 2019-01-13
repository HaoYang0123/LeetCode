//Leetcode 729
//有序树（Hash，C++的map，无序是unordered_map）。

class MyCalendar {
public:
    map<int, int> cal;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto ind = cal.lower_bound(start); //lower_bound查找第一个大于等于start的key
        if(ind != cal.end() && ind->first < end) return false;
        if(ind != cal.begin() && (--ind)->second > start) return false; //只能 使用--ind，而不能使用ind-1（因为迭代器不支持这种操作）
        cal[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
