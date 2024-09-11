#include <iostream> 

using namespace std;


class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        int xor_bits = start ^ goal;

        while(xor_bits != 0){
            count += xor_bits & 1;
            xor_bits >>= 1;
        }

        return count;
    } 
};

int main(){

    return 0;
}