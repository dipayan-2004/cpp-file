#include <iostream>
#include <fstream>  // For file handling
#include <vector>
#include <queue>

using namespace std;

#define Max 100 

void bfs(int start, int adj[Max][Max], int V) {
    vector<bool> visited(V, false); //  --- initialising the vector with false
    queue<char> q;

    // Start BFS from the given node
    visited[int(start)-65] = true;
    q.push(start);

    while (!q.empty()) {
        char node = q.front();
        q.pop();
        cout << node << " "; // Process node
        int idx = int(node)-65;
        
        // Traverse all adjacent nodes using adjacency matrix
        for (int i = 0; i < V; i++) {
            if (adj[idx][i] == 1 && !visited[i]) { // Check if edge exists and unvisited
                visited[i] = true;
                q.push(char( i+65 ));
            }
        }
    }
}

int main() {
    ifstream file("graph.txt"); // Open file for reading

    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int V; // Number of vertices
    file >> V; // Read number of vertices from file

    int adj[Max][Max]; // Adjacency matrix

    // Read adjacency matrix from file
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            file >> adj[i][j];
        }
    }

    file.close(); // Close the file

    cout << "BFS Traversal: ";
    bfs(0, adj, V); // Start BFS from node 0

    return 0;
}
