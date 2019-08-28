//Leetcode 1172
//使用两个set居然超时了，还不如网上用的vector？没明白为何这个速度不行

//方法1：超时
class DinnerPlates {
public:
    vector<stack<int>> data;
    int cap;
    set<int> can_insert, has_value;
    DinnerPlates(int capacity) {
        data.resize(200000);
        cap = capacity;
    }
    
    void push(int val) {
        if(can_insert.size()==0) {
            if(has_value.size()>0) {
                int cur_index = *has_value.rbegin();
                if(data[cur_index].size()==cap) ++cur_index;
                //cout<<val<<"\t"<<cur_index<<endl;
                data[cur_index].push(val);
                has_value.insert(cur_index);
            }
            else {
                int cur_index = 0;
                if(data[cur_index].size()==cap) ++cur_index;
                data[cur_index].push(val);
                has_value.insert(cur_index);
            }
        }
        else {
            auto ind = can_insert.begin();
            int ind0 = *ind;
            data[ind0].push(val);
            if(data[ind0].size()==cap) can_insert.erase(ind);
            has_value.insert(ind0);
        }
    }
    
    int pop() {
        if(has_value.size()==0) return -1;
        auto ind = has_value.rbegin();
        int ind0 = *ind;
        int res = data[ind0].top();
        data[ind0].pop();
        can_insert.insert(ind0);
        if(data[ind0].size()==0) has_value.erase(ind0);
        //cout<<"POP\t"<<res<<"\t"<<has_value.size()<<endl;
        return res;
    }
    
    int popAtStack(int index) {
        if(index < 0 || data[index].size()==0) return -1;
        int res = data[index].top();
        data[index].pop();
        can_insert.insert(index);
        if(data[index].size()==0) has_value.erase(index);
        return res;
    }
};

//方法2：网上代码，不超时。感觉是由于案例的stack的capacity是2，很少所以经常会调用set的更新，而这个代码不会
class DinnerPlates {
public:
    vector<vector<int>> v;
    int c, max, nextr;
    
    DinnerPlates(int capacity) {
        c = capacity;
        v = vector<vector<int>>(100002, vector<int>());
        nextr = 0;
        max = 0;
    }
    
    void push(int val) {
        v[nextr].push_back(val);

        while(nextr < v.size() && v[nextr].size() == c){
            nextr++;
        }
        if(nextr > max){
            //correctly set value for max;
            max = (v[nextr].size() > 0) ? nextr : nextr-1;
        }
    }
    
    int pop() {
        int s = v[max].size();
        if(max <= 0 && s == 0){
            return -1;
        }
        int t = v[max][s-1];
        v[max].pop_back();
        while(v[max].size() == 0 && max > 0){
            max--;
        }
        if(nextr > max) nextr = max;
        return t;
    }
    
    int popAtStack(int index) {
        int s = v[index].size();
        if(s == 0){
            return -1;
        }
        int t = v[index][s-1]; 
        v[index].pop_back();
        if(index < nextr) nextr = index;
        if(v[index].size() == 0 && index == max && max > 0){
            max--;
        }
        return t;
    }
};

