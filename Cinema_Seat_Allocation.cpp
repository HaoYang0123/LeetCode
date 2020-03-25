//Leetcode 1386

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> seats; //用vector会超内存
        for(int i=0;i<reservedSeats.size();++i) {
            vector<int> & s = reservedSeats[i];
            if(s[1]<= 1 || s[1] >= 10) {
                continue; //将十个座位变成8个（第1个和最后1个不用管，因为肯定四人不能坐在这两个座位上）
            }
            seats[s[0]] |= 1<<(s[1] - 2); 
        }
        
        int res = 2*n;
        for(auto seat : seats) {
            int row_seat = seat.second;
            bool p1 = !(row_seat & 0b11110000); //前面四个位置可以坐人
            bool p2 = !(row_seat & 0b00111100); //中间四个位置可以坐人
            bool p3 = !(row_seat & 0b00001111); //最后四个位置可以坐人
            cout<<seat.first<<"\t"<<p1<<"\t"<<p2<<"\t"<<p3<<endl;
            if(p1 && p3) continue;
            else if(p1 || p2 || p3) res -= 1;
            else res -= 2;
        }
        return res;
    }
};
