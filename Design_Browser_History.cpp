//Leetcode 1472

class BrowserHistory {
public:
    vector<string> pages;
    int cur_ind, num;
    BrowserHistory(string homepage) {
        pages.push_back(homepage);
        cur_ind = 0;
        num = 1;
    }
    
    void visit(string url) {
        if(cur_ind == num-1) {
            pages.push_back(url);
            ++cur_ind;
            ++num;
        }
        else {
            pages.resize(cur_ind+1);
            pages.push_back(url);
            ++cur_ind;
            num = pages.size();
        }
    }
    
    string back(int steps) {
        cur_ind -= steps;
        cur_ind = max(0, cur_ind);
        return pages[cur_ind];
    }
    
    string forward(int steps) {
        cur_ind += steps;
        cur_ind = min(cur_ind, num-1);
        return pages[cur_ind];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
