//Leetcode 1366

int cmp(const pair<int,vector<int>> & a, const pair<int,vector<int>> & b) {
    for(int i=0;i<26;++i) {
        if(a.second[i]<b.second[i]) return -1;
        else if(a.second[i]>b.second[i]) return 1;
    }
    return 0;
}

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<pair<int, vector<int>>> data;
        for(int i=0;i<26;++i) {
            data.push_back(pair<int, vector<int>>(i, vector<int>(26,0)));
        }
        for(int i=0;i<votes.size();++i) {
            string & v = votes[i];
            for(int j=0;j<v.length();++j) {
                data[int(v[j]-'A')].second[j]++;
            }
        }
        //sort(data.begin(),data.end(),cmp); //sort不稳定排序
        for(int i=0;i<data.size();++i) {
            for(int j=i+1;j<data.size();++j) {
                int flag = cmp(data[i], data[j]);
                if(flag == -1) {
                    auto tmp = data[i];
                    data[i] = data[j];
                    data[j] = tmp;
                }
            }    
        }
        char tmp[27];
        int i=0;
        for(;i<votes[0].length();++i) tmp[i] = char(data[i].first+'A');
        tmp[i] = '\0';
        return string(tmp);
    }
};

//stable_sort，进行稳定排序

bool cmp(const pair<int,vector<int>> & a, const pair<int,vector<int>> & b) {
    for(int i=0;i<26;++i) {
        if(a.second[i]<b.second[i]) return false;
        else if(a.second[i]>b.second[i]) return true;
    }
    return false;
}

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<pair<int, vector<int>>> data;
        for(int i=0;i<26;++i) {
            data.push_back(pair<int, vector<int>>(i, vector<int>(26,0)));
        }
        for(int i=0;i<votes.size();++i) {
            string & v = votes[i];
            for(int j=0;j<v.length();++j) {
                data[int(v[j]-'A')].second[j]++;
            }
        }
        stable_sort(data.begin(),data.end(),cmp);
        char tmp[27];
        int i=0;
        for(;i<votes[0].length();++i) tmp[i] = char(data[i].first+'A');
        tmp[i] = '\0';
        return string(tmp);
    }
};
