//Leetcode 1233

class OneFolder {
public:
    vector<string> fname;
    
public:
    OneFolder(vector<string> & name) {
        this->fname = name;
    }
    
    void write() {
        for(int i=0;i<this->fname.size();++i)
            cout<<this->fname[i]<<"\t";
        cout<<endl;
    }
    string get_string() {
        string res = "";
        for(int i=0;i<this->fname.size();++i) res += "/" + this->fname[i];
        return res;
    }
};

bool cmp(const OneFolder & a, const OneFolder & b) {
    return a.fname.size() < b.fname.size();
}

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<OneFolder> all_folders;
        for(int i=0;i<folder.size();++i) all_folders.push_back(getFolder(folder[i]));
        sort(all_folders.begin(), all_folders.end(), cmp);
        //cout<<all_folders.size()<<endl;
        //for(int i=0;i<all_folders.size();++i) all_folders[i].write();
        vector<string> res;
        vector<unordered_map<string, bool>> folder_floor(all_folders.back().fname.size());
        //folder_floor[i]表示第i层中有哪些文件夹
        for(int i=0;i<all_folders.size();++i) {
            vector<string> & fname = all_folders[i].fname;
            bool is_sub_folder = false;
            for(int j=0;j<fname.size();++j) {
                unordered_map<string, bool> & one_floor = folder_floor[j];
                auto ind = one_floor.find(fname[j]);
                if(ind == one_floor.end()) one_floor[fname[j]] = (j==fname.size()-1);
                else {
                    if(ind->second) {
                        is_sub_folder = true;
                        break;
                    }
                }
            }
            if(!is_sub_folder) res.push_back(all_folders[i].get_string());
        }
        return res;
    }
    
    OneFolder getFolder(string & str) {
        string cur = "";
        vector<string> fname;
        for(int i=0; i<str.length(); ++i) {
            if(str[i] != '/') cur += str[i];
            else {
                if(cur != "") fname.push_back(cur);
                cur = "";
            }
        }
        if(cur != "") fname.push_back(cur);
        return OneFolder(fname);
    }
};
