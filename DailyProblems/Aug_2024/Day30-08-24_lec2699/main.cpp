#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // idea 
    // first --> find the paths from source to destination 
    // second: --> choose the path 
    // then the modifile and fush it into the resutl 
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<int>> result;

        // step 1: find the path from the source to the destination
        vector<vector<int>> path;
        vector<int> weightOfPath;


    }

    void dfs(int n, vector<vector<int>>& edges, int source, int destination, vector<vector<int>>& path, vector<int> weigthOfPath){
        if(n == 0){
            return;
        }

        queue<int> q;
        q.push(source);
        vector<int> mark(n, 0);

        int weight = 0;
        while(!q.empty()){
            if()
        }
        
    }
    
};

int main(){
    return 0;
}