#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
        visited[node] = 1;
        for (int j = 0; j < graph.size(); j++) {
            if (graph[node][j] == 1 && !visited[j]) {
                dfs(j, graph, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, isConnected, visited);
            }
        }
        return count;
    }
};
