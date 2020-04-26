//Leetcode 1418

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> food;
        set<int> tables;
        unordered_map<string, int> tf2num;
        int order_num = orders.size();
        for(int i=0;i<order_num;++i) {
            tables.insert(atoi(orders[i][1].c_str()));
            food.insert(orders[i][2]);
            string tf = orders[i][1] + "@" + orders[i][2];
            tf2num[tf]++;
        }
        vector<vector<string>> res;
        vector<string> headers;
        headers.push_back("Table");
        for(auto ind = food.begin(); ind != food.end(); ++ind) headers.push_back(*ind);
        res.push_back(headers); //添加表头
        for(auto ind = tables.begin(); ind != tables.end(); ++ind) {
            vector<string> cols;
            cols.push_back(to_string(*ind));
            for(auto ind2 = food.begin(); ind2 != food.end(); ++ind2) {
                string tf = to_string(*ind) + "@" + (*ind2);
                cols.push_back(to_string(tf2num[tf]));
            }
            res.push_back(cols);
        }
        return res;
    }
};
