// Leetcode 2166

class Bitset {
public:
    unordered_set<int> ones;
    int size, flip_flag;  //flip_flag为false表示ones存储的是为1的索引位置，如果flip_flag为true，则表示ones存储的是为0的索引位置
    Bitset(int size) {
        this->size = size;
        this->flip_flag = false;
    }
    
    void fix(int idx) {
        if(!flip_flag)
            ones.insert(idx);
        else {
            auto i = ones.find(idx);
            if(i != ones.end())
                ones.erase(i);
        }
    }
    
    void unfix(int idx) {
        if(!flip_flag) {
            auto i = ones.find(idx);
            if(i != ones.end())
                ones.erase(i);
        }
        else
            ones.insert(idx);
    }
    
    void flip() {
        this->flip_flag = !this->flip_flag;
    }
    
    bool all() {
        if(!flip_flag)
            return ones.size() == size;
        else
            return ones.size() == 0;
    }
    
    bool one() {
        if(!flip_flag)
            return ones.size() > 0;
        else
            return ones.size() < size;
    }
    
    int count() {
        if(!flip_flag)
            return ones.size();
        else
            return size - ones.size();
    }
    
    string toString() {
        string res = "";
        if(!flip_flag) {
            for(int i=0; i<size; ++i) {
                if(ones.find(i) == ones.end()) res += '0';
                else res += '1';
            }
        }
        else {
            for(int i=0; i<size; ++i) {
                if(ones.find(i) != ones.end()) res += '0';
                else res += '1';
            }
        }
        return res;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
