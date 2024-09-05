#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sumOfRolls = 0;
        for(auto x : rolls){
            sumOfRolls += x;
        }

        vector<int> result(n, 0);
        int sumOfMissingRolls = (n + rolls.size()) * mean - sumOfRolls;
        if(!(sumOfMissingRolls <= 6 * n && sumOfMissingRolls >= n)){
            return {};
        }

        divide(result, sumOfMissingRolls);

        return result;
    }

    void divide(vector<int>& rolls, int sum){
        int size = rolls.size();
        int temp = sum / size;
        sum = sum - temp * size;
        
        for(int i = 0; i < size; i++){
            if(sum > 0){
                rolls[i] = 1 + temp;
                sum--;
            }
            else{
                rolls[i] = temp;
            }
            
        }
    }
};

// optimize 
static const int optimize = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int main(){

    return 0;
}