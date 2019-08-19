//Leetcode 1156

class Solution {
public:
    int maxRepOpt1(string text) {
        vector<vector<pair<int,int>>> aa2pos(26, vector<pair<int,int>>());
        int cur_ind = int(text[0]-'a');
        int start = 0, end = 0;
        for(int i=1;i<text.length();++i) {
            int new_ind = int(text[i]-'a');
            if(new_ind == cur_ind) {
                end = i;
            }
            else {
                aa2pos[cur_ind].push_back(pair<int,int>(start, end));
                cur_ind = new_ind;
                start = i;
                end = i;
            }
        }
        aa2pos[cur_ind].push_back(pair<int,int>(start, end));
        
        int res = 1;
        for(int i=0;i<26;++i) { //枚举所有字符，从'a'至'z'
            if(aa2pos[i].size()==0) continue; //如果字符没出现过，则不考虑
            int cur_len_max = 0;
            vector<pair<int,int>> & pos = aa2pos[i];
            if(pos.size()==1) cur_len_max = get_len(pos[0]); //如果当前字符连续出现的次数为1，则长度就是这次连续出现的长度
            else {
                for(int j=0;j<pos.size()-1;++j) {
                    if(pos[j].second+2==pos[j+1].first) { //如果当前连续的位置与下一个连续位置相邻（差一个其它字符）
                        int flag = 0;
                        if(pos.size()>2) flag = 1; //如果出现的连续次数大于2次（3次及以上），则说明可以将这两次连续外的其它连续字符与中简的字符替换
                        int cur_len = (get_len(pos[j])+get_len(pos[j+1])+flag); //出现的长度为这两次连续出现字符的长度和
                        cur_len_max = max(cur_len_max, cur_len);
                    }
                    else {
                        int cur_len = get_len(pos[j]) + 1; //如果当前连续位置不与下一个连接，则只能是当前连续长度，+1表示可以将其它连续位置与两边字符替换
                        cur_len_max = max(cur_len_max, cur_len);
                    }
                }
                int cur_len = get_len(pos[pos.size()-1]) + 1; //需要将最后一个的连续长度考虑
                cur_len_max = max(cur_len_max, cur_len);
            }
            res = max(res, cur_len_max);
        }
        return res;
    }
    
    int get_len(pair<int,int> & p) {
        return p.second-p.first+1;
    }
};
