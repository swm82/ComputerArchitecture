#include "../graphutils.h" 

graphNode_t *primsMST(AdjacencyListNode* g, size_t V);
void findMin(AdjacencyListNode *g, size_t V, graphNode_t *parents, graphNode_t *minSource, graphNode_t *minDest);
double updateMin(graphNode_t *minSource, graphNode_t *minDest, graphNode_t source, AdjacencyListNode *dest);
void printNodes(size_t V, graphNode_t *parents);

int main ( int argc, char* argv[] ) {

    AdjacencyListNode* adjacencyList;
    size_t graphNodeCount = adjMatrixToList(argv[1], &adjacencyList);

    graphNode_t *parents = primsMST(adjacencyList, graphNodeCount);

    printNodes(graphNodeCount, parents);

    free (parents);
    freeAdjList ( graphNodeCount, adjacencyList );

    return EXIT_SUCCESS;
}

// O(E*V)
graphNode_t *primsMST(AdjacencyListNode* g, size_t V) {
    graphNode_t* parents = calloc( V, sizeof(graphNode_t) );
    for (size_t i=0; i<V; i++) {
        parents[i] = -1; 
    }

    graphNode_t root = rand()%V;
    parents[root] = root;

    for (unsigned iter=0; iter<V-1; iter++) { 
        graphNode_t minSource = -1;
        graphNode_t minDest = -1;
        findMin(g, V, parents, &minSource, &minDest);
        parents[minDest] = minSource;
    }
    return parents;
}

// Helper method to find next minimum weight between a tree node and non tree node
void findMin(AdjacencyListNode *g, size_t V, graphNode_t *parents, graphNode_t *minSource, graphNode_t *minDest) {
    double minWeight = DBL_MAX; 
    for (graphNode_t source=0; source<V; source++) {
        if (parents[source] != -1) {
            AdjacencyListNode *curr = g[source].next;
            while (curr) {
                if (curr->weight < minWeight && parents[curr->graphNode] == -1) { 
                    minWeight = updateMin(minSource, minDest, source, curr);
                }
                curr = curr->next;
            }
        }
    }
}

double updateMin(graphNode_t *minSource, graphNode_t *minDest, graphNode_t source, AdjacencyListNode *dest) {
    *minSource = source;
    *minDest = dest->graphNode;
    return dest->weight;
}

void printNodes(size_t V, graphNode_t *parents) {
    for (size_t i = 0; i < V; i++) {
        if (i != parents[i]) printf("%ld %ld\n", parents[i], i);
    }
    puts("");
}
