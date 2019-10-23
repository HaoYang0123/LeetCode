//Leetcode 1234
//方法1：Wrong answer，因为查找(i,j)包含need_find_key并不正确

class Solution {
public:
    int balancedString(string s) {
        int q=0,w=0,e=0,r=0;
        for(int i=0;i<s.length();++i) {
            if(s[i]=='Q') ++q;
            else if(s[i]=='W') ++w;
            else if(s[i]=='E') ++e;
            else ++r;
        }
        int mean = s.length() / 4;
        map<char, int> need_find;
        if(q>mean) need_find['Q'] = q-mean;
        if(w>mean) need_find['W'] = w-mean;
        if(e>mean) need_find['E'] = e-mean;
        if(r>mean) need_find['R'] = r-mean;
        if(need_find.size() == 0) return 0;
        string need_find_key = get_key(need_find);
        cout<<need_find_key<<endl;
        map<string, int> key2ind;
        map<char, int> cur_find;
        int res = INT_MAX;
        for(int i=0;i<s.length();++i) {
            if(need_find.find(s[i]) != need_find.end()) cur_find[s[i]]++;
            string key = get_key(cur_find);
            //if(i==16) cout<<"Final\t"<<key<<endl;
            if(key == need_find_key) res = min(res, i+1);
            map<char, int> sub_find;
            bool flag = true;
            if(cur_find.size() < need_find.size()) flag = false;
            else {
                for(auto ind = cur_find.begin(); ind != cur_find.end(); ++ind) {
                    if(ind->second < need_find[ind->first]) {
                        flag = false;
                        break;
                    }
                    if(ind->second > need_find[ind->first]) sub_find[ind->first] = (ind->second-need_find[ind->first]);
                }
            }
            //if(i==16) cout<<"Final\t"<<flag<<endl;
            if(flag) {
                string sub_key = get_key(sub_find);
                //if(i==16) cout<<"Sub\t"<<sub_key<<endl;
                if(key2ind.find(sub_key) != key2ind.end()) res = min(res, (i-key2ind[sub_key]));
            }
            key2ind[key] = i;
        }
        return res;
    }
    
    string get_key(map<char, int> & need_find) {
        string res = "";
        for(auto ind = need_find.begin(); ind != need_find.end(); ++ind) {
            //cout<<ind->first<<"\t"<<ind->second<<endl;
            res += ind->first + to_string(ind->second);
        }
        return res;
    }
};

//方法2，正确答案。查找(i,j)使得其余部分的Q\W\E\R数量均小于等于n（n=s.size()/4）
class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> char2num;
        for(int i=0;i<s.length();++i) char2num[s[i]]++;
        int mean = s.length()/4;
        int res = INT_MAX;
        for(int i=0,j=0;i<s.length();++i) {
            --char2num[s[i]];
            while(j<=i+1 && is_ok(char2num, mean)) { //(j-i)
                res = min(res, i-j+1);
                ++char2num[s[j]];
                ++j;
            }
        }
        return res;
    }
    
    bool is_ok(unordered_map<char,int> & char2num, int mean) {
        for(auto ind = char2num.begin(); ind != char2num.end(); ++ind) {
            if(ind->second > mean) return false;
        }
        return true;
    }
};
