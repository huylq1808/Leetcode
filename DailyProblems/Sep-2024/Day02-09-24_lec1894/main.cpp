#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        if(n <= 1){
            return 0;
        }

        long long sum = 0;

        for(int i = 0; i < n; i++){
            sum += chalk[i];
        }

        if(k >= sum){
            k -= sum;
        }

        for(int i = 0; i < n; i++){
            k -= chalk[i];
            if(k < 0){
                return i;
            }
        }

        return 0;
    }
};

// wwe can using binary search for this problems 
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();

        vector<long> prefixSum(n);
        prefixSum[0] = chalk[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + chalk[i];
        }

        long sum = prefixSum[n - 1];
        long remainingChalk = (k % sum);

        return binarySearch(prefixSum, remainingChalk);
    }

private:
    int binarySearch(vector<long>& arr, long tar) {
        int low = 0, high = arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] <= tar) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return high;
    }
};

int main(){

    return 0;
}