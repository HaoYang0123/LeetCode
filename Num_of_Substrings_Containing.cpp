//Leetcode 1358
//start-end窗口记录当前窗口中a、b、c出现的次数

//方法1：自己写的双指针，代码看起来不太美观
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

//方法2：看了网上的代码后，自己写的
//只有一个for循环，两个分支：1）如果满足条件则更新start（同时，更新结果res）；2）如果不满足条件则更新end
class Solution {
public:
    int numberOfSubstrings(string s) {
        int s_len = s.length(), res = 0;
        int start = 0, end = 0;
        int a_num = 0, b_num = 0, c_num = 0;
        while(end <= s_len) { //注：end可以至最后的s_len
            if(a_num > 0 && b_num > 0 && c_num > 0) {
                //cout<<start<<"\t"<<end<<endl;
                res += (s_len - end + 1);
                if(s[start] == 'a') --a_num;
                else if(s[start] == 'b') --b_num;
                else --c_num;
                ++start;
            }
            else {
                if(end == s_len) break; //注：防止数组越界
                if(s[end] == 'a') ++a_num;
                else if(s[end] == 'b') ++b_num;
                else ++c_num;
                ++end;
            }
        }
        return res;
    }
};
