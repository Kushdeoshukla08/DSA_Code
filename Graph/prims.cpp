#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int minKey(const vector<int>& key, const vector<bool>& mstSet, int V) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }

    return minIndex;
}

void printMST(const vector<int>& parent, const vector<vector<int>>& graph) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < graph.size(); i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}

void primMST(const vector<vector<int>>& graph, int V) {
    vector<int> parent(V); 
    vector<int> key(V, INT_MAX); 
    vector<bool> mstSet(V, false);

    key[0] = 0;   
    parent[0] = -1;

    
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);

        mstSet[u] = true; 
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    printMST(parent, graph);
}

int main() {
    int V; 
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix of the graph:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    primMST(graph, V);

    return 0;
}
