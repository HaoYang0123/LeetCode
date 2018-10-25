//Leetcode 842
//没什么算法，就是枚举前两个数字，判断是否为Fibonacci数列。
//但是特别容易出错。

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        for(int i=0;i<S.length()-2;++i) {
            vector<int> res;
            int a = atoi(S.substr(0,i+1).c_str());
            if(a<0) break;
            if(S[0]=='0' && i>1) continue;
            int old_a = a;
            //cout<<"A"<<'\t'<<a<<endl;
            int a_len = i+1;
            res.push_back(a);
            for(int j=i+1;j<S.length()-1;++j) {
                if(j-i>1 && S[i+1]=='0') continue; //01数字不合法
                int b = atoi(S.substr(i+1,j-i).c_str());
                if(b<0) break;
                //cout<<"B"<<'\t'<<b<<endl;
                int b_len = j-i;
                int k=j+1;
                bool flag = true;
                int c = 0;
                a = old_a;
                while(k<S.length()) {
                    int c_len = (b_len>a_len?b_len:a_len);
                    if(k+c_len>S.length()) {
                        flag = false;
                        break;
                    }
                    if(c_len>1 && S[k]=='0') {
                        flag = false;
                        break; //01数字不合法
                    }
                    c = atoi(S.substr(k,c_len).c_str());
                    if(c<0) {
                        flag = false;
                        break;
                    }
                    //cout<<"A+B"<<"\t"<<a<<"\t"<<b<<"\t"<<c<<endl;
                    if(c!=a+b) { //a+b可能已经进位了，那么多一个长度
                        c_len++;
                        if(k+c_len>S.length()) {
                            flag = false;
                            break;
                        }
                        c = atoi(S.substr(k,c_len).c_str());
                        if(c<0) {
                            flag = false;
                            break;
                        }
                        //cout<<"A+B(2)"<<"\t"<<a<<"\t"<<b<<"\t"<<c<<endl;
                        if(c!=a+b) {
                            flag = false;
                            break;
                        }
                        else {
                            res.push_back(b);
                            a = b;
                            b = c;
                            k = k + c_len;
                            a_len = b_len;
                            b_len = c_len;
                        }
                    }
                    else {
                        res.push_back(b);
                        a = b;
                        b = c;
                        k = k + c_len;
                        a_len = b_len;
                        b_len = c_len;
                    }
                }
                //cout<<k<<"\t"<<flag<<endl;
                if(!flag) continue;
                else {
                    res.push_back(c);
                    return res;
                }
            }
        }
        return vector<int>();
    }

};
