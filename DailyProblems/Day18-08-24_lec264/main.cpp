#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
    // using priority queue and set
    int nthUglyNumber(int n) {
        std::vector<int> uglyNum{2, 3, 5};
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> minHeap;
        std::unordered_set<long long> seen;

        minHeap.push(1);
        seen.insert(1);
        long long ugly = 1;

        for (int i = 0; i < n; ++i) {
            ugly = minHeap.top();
            minHeap.pop();

            for (int x : uglyNum) {
                long long newUgly = ugly * x;
                if (seen.find(newUgly) == seen.end()) {
                    minHeap.push(newUgly);
                    seen.insert(newUgly);
                }
            }
        }

        return int(ugly);
    }

    // using array and math 
    int nthUglyNumber(int n) {
        //initializing the arr 
        vector<int>arr(n+1);
        //creating the pointers
        int i2;
        int i3;
        int i5;
        i2=i3=i5=1;
        arr[1]=1;// first ugly number is 1 alwyas

        for(int i=2;i<n+1;i++){
            //computing the values
            int i2ug=arr[i2]*2;
            int i3ug=arr[i3]*3;
            int i5ug=arr[i5]*5;
            //finding out which one is minimum
            int minug=min(i2ug,min(i3ug,i5ug));
            //feedin the minug
            arr[i]=minug;
            //increment of pointer
            if(minug==i2ug) i2++;
            if(minug==i3ug) i3++;
            if(minug==i5ug) i5++;
        }
        return arr[n];
    }
};

int main(){
    Solution solution;

    cout << solution.nthUglyNumber(10);


    return 0;
}