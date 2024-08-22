#include <iostream>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int numBits = 0;
        int temp = num;

        while(temp > 0){
            numBits++;
            temp >>= 1;
        }

        long long result = 1;
        result <<= numBits;
        result--;
        
        result ^= num;
        
        return int(result);
    }
};

int main(){
    Solution solution;
    cout << solution.findComplement(5);
    cout << INT_MIN << endl << INT_MAX;
}