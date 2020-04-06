//Leetcode 1396

class UndergroundSystem {
public:
    unordered_map<int, string> id2name;
    unordered_map<int, int> id2time;
    unordered_map<string, vector<int>> name2pass;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        id2name[id] = stationName;
        id2time[id] = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        string name = id2name[id];
        int starttime = id2time[id];
        string s2e = name + "@" + stationName;
        int transtime = (t - starttime);
        name2pass[s2e].push_back(transtime);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string s2e = startStation + "@" + endStation;
        vector<int> & val = name2pass[s2e];
        double res = 0.0;
        for(int i = 0; i < val.size(); ++i) res += val[i];
        return res / val.size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
