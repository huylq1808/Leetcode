#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public: 
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        if(arr.size() < 0){
            return {};
        }

        int n = arr.size();
        vector<vector<int>> prefixSum(n, vector<int>(n, 0));
        vector<int> result(queries.size());

        //set the begin num 
        for(int i = 0; i < n; i++){
            prefixSum[i][i] = arr[i];
        }

        // using xorValue function 
        for(int i = 0; i < queries.size(); i++){
            result[i] = xorValue(queries[i][0], queries[i][1], prefixSum);
        }

        return result;  
    }

    int xorValue(int begin, int end, vector<vector<int>>& prefixSum){
        if(end < begin){
            return 0;
        }

        if(prefixSum[begin][end] != 0){
            return prefixSum[begin][end];
        }

        prefixSum[begin][end] = xorValue(begin, end - 1, prefixSum);

        return prefixSum[begin][end];
    }
};


// another version with using less memory
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int n = arr.size();
    vector<int> prefixXor(n + 1, 0);
    vector<int> result(queries.size());

    // calculate the prefix 
    for (int i = 0; i < n; i++) {
        prefixXor[i + 1] = prefixXor[i] ^ arr[i];
    }

    // solve the queries 
    for (int i = 0; i < queries.size(); i++) {
        int l = queries[i][0];
        int r = queries[i][1];
        result[i] = prefixXor[r + 1] ^ prefixXor[l];
    }

    return result;
}

int main(){


    return 0;
}
