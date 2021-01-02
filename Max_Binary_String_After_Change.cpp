// Leetcode 1702

class Solution {
public:
    string maximumBinaryString(string binary) {
        int zero_num = 0, start_ind = -1; //0的数量
        for(int i = 0; i < binary.length(); ++i) {
            if(binary[i] == '0') {
                ++zero_num;
                if(start_ind == -1) start_ind = i;
            }
        }
        if(zero_num == 0) return binary; //如果没有0，则不用转换
        int zero_ind = zero_num - 1; //将第zero_num-1设置成0，其余位置为1
        for(int i = 0; i < binary.length(); ++i) binary[i] = '1';
        binary[start_ind + zero_ind] = '0';
        return binary;
    }
};
