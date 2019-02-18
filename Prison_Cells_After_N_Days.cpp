//Leetcode 957

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<vector<int>> dp;
        dp.push_back(cells);
        int v = get_key(cells);
        unordered_map<int, int> mm; //mm[i]表示值为i的对应于dp中的索引位置
        mm[v] = 0;
        int n = N, find_index = -1;
        while(n > 0) {
          vector<int> new_cells = update(cells);
                int key = get_key(new_cells);
                if(mm.find(key) != mm.end()) { //关键是这一步，即不用计算N步。如果计算到某步时发现已经在原来的状态，即出现了环，则直接退出
                    find_index = mm[key];
                    break;
                } 
                mm[key] = dp.size();
                cells = new_cells;
                dp.push_back(cells);
          --n;
        }
        if(n <= 0) return dp[dp.size()-1];
        //下面一行代码表示出现了环，那么find_index表示环开始的位置，从[find_index, dp.size()-1]表示出现了环
        return dp[find_index + (N - find_index) % (dp.size() - find_index)];
    }
    
    int get_key(vector<int> & cells) { //返回cells对应的状态码
        int res = 0, bit = 1;
        for(int i=cells.size()-1;i>=0;--i) {
            res += (bit * cells[i]);
            bit *= 2;
        }
		return res;
    }
	
	vector<int> update(vector<int> & cells) {
        vector<int> res = cells;
        res[0] = 0;
        res[7] = 0;
        for(int i=1;i<7;++i) {
            if(cells[i-1]==cells[i+1]) res[i] = 1;
            else res[i] = 0;
        }
        return res;
	}
};
