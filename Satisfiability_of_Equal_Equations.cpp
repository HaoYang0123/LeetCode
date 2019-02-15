//Leetcode 990

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> data(26,0);
        for(int i=0;i<26;++i) data[i] = i;
        vector<int> no_equal; //存储不相等的数据
        for(int i=0;i<equations.size();++i) {
            string eq = equations[i];
            if(eq[1] == '!') {
                no_equal.push_back(i);
                continue;
            }
            //只处理相等的数据
            int ind1 = (int)(eq[0]-'a'), ind2 = (int)(eq[3]-'a');
            if(ind1 == ind2) continue; //如果是"a==a"这种形式，不处理
            update_data(data, ind1, ind2); //更新数据，将在data数组中值等于data[ind2]，全部更新为data[ind1]，表明这两个“圈子”的所有元素合并成一个“圈子”
        }
        //查看不相等的数据，如果对应的值是相等的，则出现矛盾，返回false
        for(int i=0;i<no_equal.size();++i) {
            string eq = equations[no_equal[i]];
            int ind1 = (int)(eq[0]-'a'), ind2 = (int)(eq[3]-'a');
            if(data[ind1] == data[ind2]) return false;
        }
        return true;
    }
    
    void update_data(vector<int> & data, int ind1, int ind2) {
        int val = data[ind2], new_val = data[ind1];
        for(int i=0;i<data.size();++i) {
            if(data[i]==val) data[i]=new_val;
        }
    }
};
