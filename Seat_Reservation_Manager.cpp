// Leetcode 1845

class SeatManager {
public:
    set<int> seats;
    int next;
    SeatManager(int n) {
        next = 1;
    }
    
    int reserve() {
        if(seats.empty()) {
            return next++;
        }
        auto ind = seats.begin();
        int res = *ind;
        seats.erase(ind);
        return res;
    }
    
    void unreserve(int seatNumber) {
        seats.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
