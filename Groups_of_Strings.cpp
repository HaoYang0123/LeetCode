// Leetcode 2157
//TLE，但思路基本正确，需要用到状态压缩，判断words[i]与words[j]是否到达。 但O(N^2)，其实没有必要，只需要O(N*(26^2))，因为words[i]，能够与此到达的可以枚举所有的2进制位，将任意一个1转成0...

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        unordered_set<int> dif;  //dif存储2进制数中只有1位为1，或者只有2位为1的int集合
        //为何只存1位为1，及2位为1的呢？因为如果words[i]与words[j]能够连接边，只有两个string的2进制数
        //经过异或运算后，只能有1位为1（表示words[i]通过增加一个字符、或者减小一个字符到达words[j]）
        //只能有2位为1，表示words[i]通过改变一个字符，到达words[j]
        dif.insert(0);  //words[i]=words[j]，也认为可以到达
        for(int i=0; i<26; ++i) {
            dif.insert((1<<i));
            for(int j=i+1; j<26; ++j) {
                int zh = (1<<i) | (1<<j);
                dif.insert(zh);
            }
        }
        int n = words.size();
        vector<vector<int>> edges(n, vector<int>());  //将words转化成一张图，如果words[i]与words[j]能够到达，则i与j连接边
        vector<bool> is_vis(n, false);
        vector<int> values(n, 0);
        //将字符串，进行状态压缩，转成2进制数
        for(int i=0; i<n; ++i) {
            values[i] = str2int(words[i]);
            //cout<<i<<"\t"<<words[i]<<"\t"<<values[i]<<endl;
        }
        //基于2进制数和dif集合，判断words[i]与words[j]是否到达，转成图graph
        for(int i=0; i<n; ++i) {
            for(int j=i+1; j<n; ++j) {
                if(abs(int(words[i].length()) - int(words[j].length())) > 1) continue;
                //如果两个字符的长度之差的绝对值超过1，那么肯定不能到达
                int v = values[i] ^ values[j];  
                if(dif.find(v) != dif.end()) {
                    //cout<<"edge\t"<<i<<"\t"<<j<<endl;
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        //使用BFS（或者DFS），在图中找并差集
        int num_set = 0, max_size = 0;
        for(int i=0; i<n; ++i) {
            if(is_vis[i]) continue;
            ++num_set;
            max_size = max(max_size, bfs(i, edges, is_vis));
        }
        return {num_set, max_size};
    }
    
    inline int bfs(int idx, vector<vector<int>> & edges, vector<bool> & is_vis) {
        //以idx为起点，BFS搜索得到与idx形成相同集合（即在graph中与idx结点互通的结点集合），返回结点集合的数量
        queue<int> qs;
        is_vis[idx] = true;
        qs.push(idx);
        int res = 1;  //idx已经在此集合中，res=1
        while(!qs.empty()) {
            int cur = qs.front();
            qs.pop();
            vector<int> & e = edges[cur];
            for(int i=0; i<e.size(); ++i) {
                if(is_vis[e[i]]) continue;
                is_vis[e[i]] = true;
                ++res;
                qs.push(e[i]);
            }
        }
        return res;
    }
    
    inline int str2int(string & word) {
        //状态压缩，将string转成一个2进制数，如果'a'在字符串中出现，则把2进制数第0位置为1；
        int res = 0;
        for(int i=0; i<word.length(); ++i) {
            int idx = int(word[i]-'a');
            res |= (1<<idx);
        }
        return res;
    }
};
