// Leetcode 1701

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        if(customers.size() == 0) return 0.0;
        int start_time = customers[0][0];
        double res = 0; //使用int会超过int表示的最大范围
        for(int i = 0; i < customers.size(); ++i) {
            start_time = max(start_time, customers[i][0]); //需要考虑：当前客人如果来得晚，厨师有可能在空等
            int end_time = start_time + customers[i][1];
            //cout<<start_time<<"\t"<<end_time<<"\t"<<(end_time - customers[i][0])<<endl;
            res += (double)(end_time - customers[i][0]);
            start_time = end_time;
        }
        //cout<<res<<endl;
        return res * 1.0 / customers.size();
    }
};
