//Leetcode 1381

class CustomStack {
public:
    deque<int> data;
    int maxSize;
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(data.size() == maxSize) return;
        data.push_front(x);
    }
    
    int pop() {
        if(data.size() == 0) return -1;
        int d = data.front();
        data.pop_front();
        return d;
    }
    
    void increment(int k, int val) {
        vector<int> new_data;
        int num = data.size();
        for(int i=0;i<k && i<num;++i) {
            int d = data.back();
            data.pop_back();
            new_data.push_back(d+val);
        }
        for(int i=new_data.size()-1;i>=0;--i) data.push_back(new_data[i]);
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
