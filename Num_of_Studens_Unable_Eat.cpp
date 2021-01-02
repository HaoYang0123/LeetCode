// Leetcode 1700

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int stu_zero_num = get_zero_num(students);
        int san_zero_num = get_zero_num(sandwiches);
        if(stu_zero_num == san_zero_num) return 0;
        
        if(stu_zero_num < san_zero_num) {
            int find_zero = san_zero_num - stu_zero_num;
            int ind = find_ind_func(sandwiches, find_zero, 0);
            return sandwiches.size() - ind;
        }
        
        int find_one = stu_zero_num - san_zero_num;
        int ind = find_ind_func(sandwiches, find_one, 1);
        return sandwiches.size() - ind;
    }
    
    inline int find_ind_func(vector<int> & bin, int find_ind, int find_val) {
        for(int i = bin.size()-1; i >= 0; --i) {
            if(bin[i] == find_val) {
                --find_ind;
                if(find_ind == 0) return i;
            }
        }
        return -1;
    }
    
    inline int get_zero_num(vector<int> & bin) {
        int num = 0;
        for(int i = 0; i < bin.size(); ++i) {
            if(bin[i] == 0) ++num;
        }
        return num;
    }
};
