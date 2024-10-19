#include <iostream>
#include <vector>

using namespace std;

bool isCyclicUtil(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
    // Mark the current node as visited and part of recursion stack
    if (!visited[node]) {
        visited[node] = true;
        recStack[node] = true;

        // Recur for all the vertices adjacent to this vertex
        for (int neighbor : adj[node]) {
            if (!visited[neighbor] && isCyclicUtil(neighbor, adj, visited, recStack))
                return true;
            else if (recStack[neighbor])
                return true;
        }
    }

    // Remove the vertex from recursion stack
    recStack[node] = false;
    return false;
}

bool isCyclic(vector<vector<int>>& adj, int numVertices) {
    // Mark all the vertices as not visited and not part of recursion stack
    vector<bool> visited(numVertices, false);
    vector<bool> recStack(numVertices, false);

    // Call the recursive helper function to detect cycle in different DFS trees
    for (int i = 0; i < numVertices; i++) {
        if (isCyclicUtil(i, adj, visited, recStack))
            return true;
    }

    return false;
}

int main() {
    // Example adjacency list
    vector<vector<int>> adj = {
        {1},    // Node 0 has an edge to node 1
        {2},    // Node 1 has an edge to node 2
        {0},    // Node 2 has an edge back to node 0 (cycle)
        {4},    // Node 3 has an edge to node 4
        {}      // Node 4 has no outgoing edges
    };

    int numVertices = adj.size();

    if (isCyclic(adj, numVertices))
        cout << "Graph contains a cycle." << endl;
    else
        cout << "Graph doesn't contain a cycle." << endl;

    return 0;
}