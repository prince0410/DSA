#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj, vector<int> &result) {
    visited[node] = true;
    result.push_back(node);

    sort(adj[node].begin(), adj[node].end());

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adj, result);
        }
    }
}

vector<int> bfsOfGraph(int V, vector<vector<int>> &adj) {
    vector<bool> visited(V, false);
    vector<int> result;
    queue<int> q;

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        sort(adj[node].begin(), adj[node].end());

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return result;
}

vector<int> dfsOfGraph(int V, vector<vector<int>> &adj) {
    vector<bool> visited(V, false);
    vector<int> result;

    dfs(0, visited, adj, result);

    return result;
}

int main() {
    int V = 5;

    vector<vector<int>> adj = {
        {2, 3, 1},
        {0},
        {0, 4},
        {0},
        {2}
    };

    vector<int> dfsResult = dfsOfGraph(V, adj);
    cout << "DFS Traversal: ";
    for (int v : dfsResult) {
        cout << v << " ";
    }
    cout << endl;

    vector<int> bfsResult = bfsOfGraph(V, adj);
    cout << "BFS Traversal: ";
    for (int v : bfsResult) {
        cout << v << " ";
    }
    cout << endl;
    cout<<"prepared 23CE140_Prince"<<endl;
    return 0;
}
