//Leetcode 1488

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> res(n, -1);
        set<int> can_dry_days, is_full_lake;
        unordered_map<int,int> lake_last_full_day; //lake_last_full_day[lake]=day表示这个lake湖是由于最近哪天（day）被水填充满的
        for(int i=0;i<rains.size();++i) {
            if(rains[i] != 0) {
                int cur_full_lake = rains[i];
                if(is_full_lake.find(cur_full_lake) != is_full_lake.end()) { //说明当前这个lake已经之前被水填充满了
                    auto can_dd = upper_bound(can_dry_days.begin(), can_dry_days.end(), lake_last_full_day[cur_full_lake]);
                    if(can_dd == can_dry_days.end()) return vector<int>(); //如果没有可以dry的天数，那么就说明无法对当前lake进行dry
                    //否则，就可以使用can_dry_days中的某一天（这里使用最早的那天）
                    res[*can_dd] = cur_full_lake;
                    can_dry_days.erase(can_dd); //由于can_dd那天已经用于dry这个cur_full_lake湖了，所以需要将其去掉
                }
                else { //说明当前这个lake之前没被水填充，那么现在就直接将其填充
                    is_full_lake.insert(cur_full_lake);
                }
                lake_last_full_day[cur_full_lake] = i;
            }
            else { //如果当天没下雨，则可以进行dry
                can_dry_days.insert(i);
            }
        }
        for(auto ind = can_dry_days.begin(); ind != can_dry_days.end(); ++ind) res[*ind] = 1; //假如还有很多可以dry的天数，需要将这些天随便添加一个“空”湖进行dry
        return res;
    }
};
