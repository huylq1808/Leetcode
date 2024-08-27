#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// soluton using BFS --> so slow 
class Solution {
public:

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> maximumProb(n, 0.0);
        maximumProb[start_node] = 1.0;
        queue<int> q;

        q.push(start_node);

        while(!q.empty()){
            int temp = q.front();
            q.pop();

            for(int i = 0; i < edges.size(); i++){
                // found the edges have node temp
                if(edges[i][0] == temp || edges[i][1] == temp){
                    int dest_pos = edges[i][0] == temp ? edges[i][1] : edges[i][0];

                    if(maximumProb[dest_pos] < maximumProb[temp] * succProb[i]){
                        maximumProb[dest_pos] = maximumProb[temp] * succProb[i];
                        
                        // push the des
                        q.push(dest_pos);
                    } 
                }
            }
        }
        
        return maximumProb[end_node];
    }
};

// solution using Dijkstra algorithm 
class Solution{
public:

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Build the adjacency list
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            graph[u].emplace_back(v, prob);
            graph[v].emplace_back(u, prob);
        }

        // Use a max-heap priority queue to store the probabilities
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        // Array to store the maximum probability to reach each node
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;

        // Dijkstra's algorithm to find the maximum probability path
        while (!pq.empty()) {
            auto [currProb, node] = pq.top();
            pq.pop();

            // If the popped node is the end_node, we have found the maximum probability path
            if (node == end_node) {
                return currProb;
            }

            // Explore neighbors
            for (auto& [neighbor, edgeProb] : graph[node]) {
                double newProb = currProb * edgeProb;

                // If a higher probability path to the neighbor is found, update and push it into the heap
                if (newProb > maxProb[neighbor]) {
                    maxProb[neighbor] = newProb;
                    pq.push({newProb, neighbor});
                }
            }
        }

        // If end_node is not reachable, return 0
        return 0.0;
    }
};

int main(){
    Solution solution;

    vector<vector<int>> edges{
        {0, 1},{1, 2}, {0, 2}
    };

    vector<double> prob{0.5, 0.5, 0, 2};

    cout << solution.maxProbability(3, edges, prob, 0, 2);
    
    return 0;
}