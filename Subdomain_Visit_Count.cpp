//Leetcode 811

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> mm;
        for(int i=0;i<cpdomains.size();++i) {
            int count = 0;
            vector<string> webs = parse_string(cpdomains[i], count);
            for(int j=0;j<webs.size();++j) {
                mm[webs[j]] += count;
            }
        }
        vector<string> res;
        for(auto ind = mm.begin(); ind != mm.end(); ++ind) {
            char tmp[10];
            sprintf(tmp, "%d", ind->second);
            string count = string(tmp);
            res.push_back(count + " " + ind->first);
        }
        return res;
    }
    
    vector<string> parse_string(string & str, int & c) {
        auto ind = str.find(' ');
        c = atoi(str.substr(0, ind).c_str());
        str = str.substr(ind+1);
        vector<string> res;
        while(str != "") {
            auto ind = str.find('.');
            if (ind == -1) {
                res.push_back(str);
                break;
            }
            res.push_back(str.substr(0, ind));
            str = str.substr(ind+1);
        }
        for(int i=res.size()-2;i>=0;--i) res[i] += "." + res[i+1];
        return res;
    }
};
