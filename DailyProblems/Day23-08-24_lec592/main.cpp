#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    string fractionAddition(string expression) {
        vector<vector<int>> dp;
        int size = expression.size();

        int pivot = 0;
        while(pivot < size){
            vector<int> fraction(2, 0);
            int counter = pivot;

            //find the numerator
            while(counter < size && expression[counter] != '/'){
                counter++;
            }
            fraction[0] = stoi(expression.substr(pivot, counter - pivot));
            counter++;
            pivot = counter;


            // find the denomirator 
            while(counter < size && expression[counter] != '+' && expression[counter] != '-'){
                counter++;
            }
            fraction[1] = stoi(expression.substr(pivot, counter - pivot));
            pivot = counter;

            // push the new fraction to fraction set
            dp.push_back(fraction);
        }

        vector<long long> totalFraction{0, 1};

        for(int i = 0; i < dp.size(); i++){
            totalFraction[0] = totalFraction[0] * dp[i][1] + totalFraction[1] * dp[i][0];
            totalFraction[1] = totalFraction[1] * dp[i][1]; 
        }

        int divisor = this->findGreatestCommonDivisor(totalFraction[0], totalFraction[1]);
        if(divisor != 0){
            totalFraction[0] /= divisor;
            totalFraction[1] /= divisor;
        }

        if(totalFraction[1] < 0){
            totalFraction[1] *= -1;
            totalFraction[0] *= -1;
        }

        return to_string(totalFraction[0]) + '/' + to_string(totalFraction[1]);
    }

    int findGreatestCommonDivisor(int x, int y) {
        while (y != 0) {
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }
};

int main(){
    Solution solution;

    cout << solution.fractionAddition("1/2+1/2+1/3-1/2+1/2+1/3");

    return 0;
}