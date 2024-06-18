#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
const int MAX_NODES = 200005;

// Stores the adjacency list for the graph
vector<int> graph[MAX_NODES];

// Stores the size of the subtree rooted at each node
ll subtree_size[MAX_NODES] = {0};

// Calculates the size of the subtree rooted at 'root'
void compute_subtree_sizes(int root, vector<int>& visited) {
    visited[root] = true;
    for (int child : graph[root]) {
        if (!visited[child]) {
            compute_subtree_sizes(child, visited);
            subtree_size[root] += subtree_size[child] + 1; // Add child's subtree size + 1 for the child itself
        }
    }
}

// Main function to read input and perform calculations
int main() {
    int num_nodes;
    cin >> num_nodes;

    // Read parent-child relationships
    for (int i = 1; i <= num_nodes; ++i) {
        int parent;
        cin >> parent;
        if (parent != -1) { // Assuming -1 represents no parent (root)
            graph[parent].push_back(i);
        } else {
            root_node = i; // Identify the root node
        }
    }

    // Initialize visited array
    vector<int> visited(num_nodes + 1, false);

    // Calculate subtree sizes starting from the root
    compute_subtree_sizes(root_node, visited);

    // Calculate total size of all subtrees
    ll total_size = 0;
    for (int i = 1; i <= num_nodes; ++i) {
        total_size += subtree_size[i];
    }

    // Output the result
    cout << total_size << endl;

    return 0;
}
