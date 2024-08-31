#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0){
            return 0;
        }

        int minPrice1 = INT_MAX;
        int maxProfit1 = 0;
        int minPrice2 = INT_MAX;
        int maxProfit2 = 0;

        for(int price : prices){
            // find the profit of the first transaction
            minPrice1 = min(minPrice1, price);
            maxProfit1 = max(maxProfit1, price - minPrice1);

            // find the profit of the second transaction --> the second transaction will be stored the first transaction
            minPrice2 = min(minPrice2, price - maxProfit1);
            maxProfit2 = max(maxProfit2, price - minPrice2); 
        }

        return maxProfit2;
    }
};


int main(){

    return 0;
}