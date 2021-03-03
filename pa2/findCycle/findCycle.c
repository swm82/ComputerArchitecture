#include "../graphutils.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A program to find a cycle in a directed graph

// You may use DFS or BFS as needed
/* ... */

#define NOT_VISITED 0
#define IN_STACK 1
#define DONE 2


typedef struct Node Node;
struct Node {
    graphNode_t vertex;
    Node *next;
};

Node *newStack();
Node *newNode(graphNode_t val);
graphNode_t pop(Node **stack);
void push(Node **stack, graphNode_t vert);
graphNode_t peek(Node **stack);
void freeStack(Node *stack);
void printList(Node **stack, graphNode_t startOfCycle);
bool DFS(AdjacencyListNode *adjList, Node **stack, graphNode_t *visited);
bool findCycle(AdjacencyListNode *adjList, size_t len);
// Debug methods
void printVisited(size_t len, graphNode_t *visited);
void printNeighbors(AdjacencyListNode *g, graphNode_t v);

int main ( int argc, char* argv[] ) {

    AdjacencyListNode* adjacencyList = NULL;
    size_t graphNodeCount = adjMatrixToList(argv[1], &adjacencyList);
    if (!findCycle(adjacencyList, graphNodeCount)) puts("DAG");
    freeAdjList ( graphNodeCount, adjacencyList );
    return EXIT_SUCCESS;
}

// *****************
// Work methods
// *****************
bool findCycle(AdjacencyListNode *adjList, size_t len) {
    graphNode_t *visited = calloc(len, sizeof(graphNode_t));
    bool hasCycle = false;
    for (size_t v = 0; v < len; v++) {
        if (visited[v] != NOT_VISITED) continue;
        Node *stack = newStack();
        push(&stack, v);
        visited[v] = IN_STACK; 
        hasCycle = DFS(adjList, &stack, visited);
        freeStack(stack);
        if (hasCycle) break;
    }
    free(visited);
    return hasCycle;
}

// Returns true if cycle found
bool DFS(AdjacencyListNode *adjList, Node **stack, graphNode_t *visited) {
    graphNode_t top = peek(stack);
    AdjacencyListNode *curr = adjList[top].next;
    bool cycle = false;
    while (curr) {
        graphNode_t adj = curr->graphNode;
        if (visited[adj] == IN_STACK) {
            printList(stack, adj);
            return true;
        } else if (visited[adj] == NOT_VISITED) {
            push(stack, adj);
            visited[adj] = IN_STACK;
            cycle = DFS(adjList, stack, visited);
            if (cycle) return true;
        }
        curr = curr->next;
    }
    visited[pop(stack)] = DONE;
    return false;
}

void printList(Node **stack, graphNode_t startOfCycle) {
    Node *stackPrint = newStack();
    push(&stackPrint, pop(stack));
    while (peek(&stackPrint) != startOfCycle) {
        push(&stackPrint, pop(stack));
    }

    while (peek(&stackPrint) != -1) {
        printf("%ld ", peek(&stackPrint));
        pop(&stackPrint);
    }
    puts("");
}

// *****************
// Stack methods
// *****************
void push(Node **stack, graphNode_t vert) {
    Node* node = newNode(vert);
    node->next = *stack;
    *stack = node;
}

graphNode_t pop(Node **stack) {
    if (*stack == NULL) return -1;
    graphNode_t val = (*stack)->vertex;
    Node* temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return val;
}

graphNode_t peek(Node **stack) {
    if (!(*stack)) return -1;
    return (*stack)->vertex;
}

// Method to increase readability
Node *newStack() {
    Node *stack = NULL;
    return stack;
}

Node *newNode(graphNode_t val) {
    Node *node = malloc(sizeof(Node));
    node->vertex = val;
    node->next = NULL;
    return node;
}

void freeStack(Node *stack) {
    if (stack == NULL) return;
    freeStack(stack->next);
    free(stack);
}

// *****************
// Debugging tools
// *****************
void printVisited(size_t len, graphNode_t *visited) {
    printf("\tVisiting: [ ");
    for (size_t i = 0; i < len; i++) {
        printf("%ld, ", visited[i]);
    }
    printf("]\n");
}

void printNeighbors(AdjacencyListNode *g, graphNode_t v) {
    AdjacencyListNode *curr = g[v].next;
    printf("[ ");
    while (curr) {
        printf("%ld, ", curr->graphNode);
        curr = curr->next;
    }
    printf("]\n");
} 