//Leetcode 1357

class Cashier {
public:
    unordered_map<int,int> id2price;
    int n;
    int cur_custome_id;
    int discount;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->cur_custome_id = 0;
        this->n = n;
        this->discount = discount;
        for(int i=0;i<products.size();++i) id2price[products[i]] = prices[i];
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double price = 0.0;
        for(int i=0;i<product.size();++i) {
            price += id2price[product[i]] * amount[i];
        }
        ++cur_custome_id;
        if(cur_custome_id == n) {
            price = price - (discount * price) / 100;
            cur_custome_id = 0;
        }
        return price;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
