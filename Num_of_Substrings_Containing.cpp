//Leetcode 1358
//start-end窗口记录当前窗口中a、b、c出现的次数

class Solution {
public:
    int numberOfSubstrings(string s) {
        int s_len = s.length(), res = 0;
        int start = 0, end = 0;
        int a_num = 0, b_num = 0, c_num = 0;
        while(start < s_len-2 && end < s_len) {
            for(; end < s_len; ++end) {
                if(s[end] == 'a') ++a_num;
                else if(s[end] == 'b') ++b_num;
                else ++c_num;
                //cout<<start<<"\t"<<end<<"\t"<<a_num<<"\t"<<b_num<<"\t"<<c_num<<endl;
                if(a_num > 0 && b_num > 0 && c_num > 0) {
                    break;
                }
            }
            //找到第1个满足要求的end
            while(start < end) { //枚举所有满足要求的start（固定当前end）
                if(a_num > 0 && b_num > 0 && c_num > 0) {
                    res += s_len - end; //固定end后，从当前end至字符串结尾均满足要求，记录个数
                    //cout<<"S\t"<<start<<"\t"<<end<<"\t"<<a_num<<"\t"<<b_num<<"\t"<<c_num<<endl;
                }
                else break; //当不满足要求时，则需要++end
                if(s[start] == 'a') --a_num;
                else if(s[start] == 'b') --b_num;
                else --c_num;
                ++start;
            }
            ++end;
        }
        return res;
    }
};
