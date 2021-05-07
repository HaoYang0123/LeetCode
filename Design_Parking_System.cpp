// Leetcode 1603

class ParkingSystem {
public:
    int b, m, s;
    ParkingSystem(int big, int medium, int small) {
        b = big;
        m = medium;
        s = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1) {
            --b;
            if(b < 0) return false;
            return true;
        }
        else if(carType == 2) {
            --m;
            if(m < 0) return false;
            return true;
        }
        --s;
        if(s < 0) return false;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
