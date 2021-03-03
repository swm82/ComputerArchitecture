#include "../graphutils.h" // header for functions to load and free adjacencyList

// A program to determine whether an undirected graph is a tree

// A recursive function that returns true if no cycles found
bool isTreeDFS (
    size_t graphNodeCount,
    AdjacencyListNode* adjacencyList,
    bool* visited,
    graphNode_t parent,
    graphNode_t current
) {

    if (visited[current]) return false;
    visited[current] = true;
    bool noCycle = false;

    AdjacencyListNode* neighbor = adjacencyList[current].next;
    while (neighbor) {
        if (neighbor->graphNode!=parent) {
            noCycle = isTreeDFS(graphNodeCount, adjacencyList, visited, current, neighbor->graphNode);
            if (!noCycle) return false;
        }
        neighbor = neighbor->next;
    }

    return true;
}

bool isTree(size_t N, AdjacencyListNode* g) {
    bool* visited = calloc ( N, sizeof(bool) );
    bool tree = isTreeDFS(N, g, visited, -1, 0);
    free(visited);
    return tree;
}

int main ( int argc, char* argv[] ) {

    AdjacencyListNode* adjacencyList = NULL;
    size_t N = adjMatrixToList(argv[1], &adjacencyList);

    printf(isTree(N, adjacencyList) ? "yes" : "no");

    freeAdjList(N, adjacencyList);

    return EXIT_SUCCESS;
}
