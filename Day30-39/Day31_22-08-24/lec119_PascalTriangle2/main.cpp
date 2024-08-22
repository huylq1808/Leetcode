#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int numRows = rowIndex + 1;
        vector<vector<int>> result(numRows);

        for(int i = 0; i < numRows; i++){
            result[i] = vector<int>(i + 1, 0);
            result[i][0] = result[i][i] = 1;

            for(int j = 1; j < i; j++){
                result[i][j] = result[i - 1][j] + result[i - 1][j - 1];
            }
        }

        return result[rowIndex];
    }
};

int main(){
    
    return 0;
}