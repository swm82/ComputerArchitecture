#include "../graphutils.h" // header for functions to load and free adjacencyList
#include <stdlib.h>
#include <stdio.h>

void printAdjList(size_t numVert, AdjacencyListNode* graph);

// A program to print the edge list of a graph given the adjacency matrix
int main ( int argc, char* argv[] ) {
    if (argc != 2)  {
        printf("Incorrect number of arguements, please include ONLY a path to input file");
        return EXIT_FAILURE;
    }
    char* path = argv[1];


    AdjacencyListNode* adjacencyList = NULL;
    size_t numNodes = adjMatrixToList(path, &adjacencyList);

    printAdjList(numNodes, adjacencyList);
    
    freeAdjList(numNodes, adjacencyList);

    return EXIT_SUCCESS;
}

void printAdjList(size_t numVert, AdjacencyListNode* graph) {
    for (size_t i = 0; i < numVert; i++) {
        AdjacencyListNode* curr = graph[i].next;
        while (curr) {
            printf("%ld %ld\n", i, curr->graphNode);
            curr = curr->next;
        }
    }
}