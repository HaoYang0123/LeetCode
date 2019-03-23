//Leetcode 799

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> glass(100, 0.0);
        if(poured<1) {
            if(query_row >= 1 || query_glass > query_row) return 0.0;
            return poured;
        }
        if(query_row == 0) {
            if(query_glass > 0) return 0.0;
            return 1.0;
        }
        poured--; //第零层的一个杯子装满，所以还剩下poured-1的水量
        glass[0] = poured * 0.5; //当前是第一层的两个杯子的水量，左右各0.5的水量
        glass[1] = poured * 0.5;
        for(int q=1;q<query_row;++q) { //后面计算到需要的query_row层，如果query_row=1，那么不用计算，因为第一层的杯子已经在上面两行计算完
            vector<double> new_glass(100, 0.0); //当前层的水量new_glass根据上一层glass来计算
            for(int i=0;i<=q;++i) { 
                if(glass[i] <= 1.0) continue; //如果glass[i]的水量已经低于1.0，说明当前杯子装不满，没有溢出
                new_glass[i] += (glass[i] - 1) * 0.5; //否则，将溢出的部分一半一半地分给左、右两个杯子中
                new_glass[i+1] += (glass[i] - 1) * 0.5;
            }
            //cout<<"===="<<q+1<<"====="<<endl;
            //write_glass(q, new_glass);
            glass = new_glass; //更新
        }
        if(glass[query_glass] > 1.0) return 1.0; //最后如果查询的杯子的水量超过1.0，说明当前杯子装满了，返回1.0
        return glass[query_glass];
    }
    
    void write_glass(int q, vector<double> & glass) {
        for(int i=0; i<=q+1;++i) cout<<glass[i]<<"\t";
        cout<<endl;
    }
};
