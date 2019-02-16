//Leetcode 981

class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, vector<string>> key_values;
    unordered_map<string, vector<int>> key_times;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        auto ind = key_values.find(key);
        auto ind2 = key_times.find(key);
        vector<string> v;
        vector<int> v2;
        if(ind != key_values.end()) v = ind->second;
        if(ind2 != key_times.end()) v2 = ind2->second;
        if(v.size() > 0 && v[v.size()-1] == value) {
            //v2[v2.size()-1] = timestamp; //注释掉再正确，虽然不注释也可以AC
        }
        else { //如果这次的value与最近插入的是一个数据，那么直接更新即可
            v.push_back(value);
            v2.push_back(timestamp);
        }
        key_values[key] = v;
        key_times[key] = v2;
    }
    
    string get(string key, int timestamp) {
        auto ind0 = key_values.find(key);
        if(ind0 == key_values.end()) return "";
        vector<string> v = ind0->second;
        vector<int> v2 = key_times[key];
        auto ind = upper_bound(v2.begin(), v2.end(), timestamp);
        if(ind == v2.begin()) return "";
        auto ind2 = (v.begin() + (int)(ind - 1 - v2.begin()));
        return *ind2;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
