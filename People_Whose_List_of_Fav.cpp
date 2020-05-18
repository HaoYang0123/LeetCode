//Leetcode 1452

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        //change string to int
        unordered_map<string, int> company2index;
        for(int i=0;i<favoriteCompanies.size();++i) {
            vector<string> & fav = favoriteCompanies[i];
            for(int j=0;j<fav.size();++j) {
                if(company2index.find(fav[j]) == company2index.end()) 
                    company2index[fav[j]] = company2index.size();
            }
        }
        vector<set<int>> fav_com(favoriteCompanies.size(), set<int>());
        for(int i=0;i<favoriteCompanies.size();++i) {
            vector<string> & fav = favoriteCompanies[i];
            for(int j=0;j<fav.size();++j) {
                fav_com[i].insert(company2index[fav[j]]);
            }
        }
        
        /*
        for(int i=0;i<fav_com.size();++i) {
            for(auto ind = fav_com[i].begin(); ind != fav_com[i].end(); ++ind) cout<<*ind<<"\t";
            cout<<endl;
        }
        */
        vector<int> res;
        for(int i=0;i<fav_com.size();++i) {
            if(!find_is_subset(fav_com, i)) res.push_back(i);
        }
        return res;
    }
    
    inline bool find_is_subset(vector<set<int>> & fav, int com) {
        for(int i=0;i<fav.size(); ++i) {
            if(i == com) continue;
            if(b_is_set_of_a(fav[i], fav[com])) return true;
        }
        return false;
    }
    
    inline bool b_is_set_of_a(set<int> & a, set<int> & b) {
        for(auto ind=b.begin(); ind != b.end(); ++ind) {
            if(a.find(*ind) == a.end()) return false;
        }
        return true;
    }
};
