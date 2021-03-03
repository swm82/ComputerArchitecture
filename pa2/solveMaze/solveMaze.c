#include "../graphutils.h" // header for functions to load and free adjacencyList
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// A program to solve a maze that may contain cycles using BFS

// BFS requires using a queue data structure
typedef struct QueueNode {
    graphNode_t graphNode;
    struct QueueNode* next;
} QueueNode;

struct Queue {
    struct QueueNode* front; // front (head) of the queue
    struct QueueNode* back; // back (tail) of the queue
};
typedef struct Queue Queue;

size_t readFile(const char* testFile, const char* queryFile, graphNode_t *start, graphNode_t* end, AdjacencyListNode** ptr);
graphNode_t *initParents(size_t N);
Queue newQueue();
Queue enqueue ( struct Queue queue, graphNode_t graphNode );
graphNode_t dequeue ( Queue* queue );
void printQ(QueueNode *front);
graphNode_t *BFS(AdjacencyListNode *adjList, graphNode_t start, graphNode_t end, size_t len);
Queue processNeighbors(Queue q, AdjacencyListNode* ptr, graphNode_t parent, graphNode_t *parents);
void printPath(size_t len, graphNode_t parents[len], graphNode_t start, graphNode_t end);
void freeQueue(Queue queue);



int main ( int argc, char* argv[] ) {

    graphNode_t start;
    graphNode_t end;
    AdjacencyListNode* adjacencyList = NULL;

    size_t graphNodeCount = readFile(argv[1], argv[2], &start, &end, &adjacencyList);
    if (graphNodeCount == -1) return EXIT_FAILURE;

    graphNode_t* parents = BFS(adjacencyList, start, end, graphNodeCount);

    printPath(graphNodeCount, parents, start, end);

    free (parents);
    freeAdjList ( graphNodeCount, adjacencyList );

    return EXIT_SUCCESS;
}

// Handle file reading/parsing and graph setup.  Returns number of vertices in graph
size_t readFile(const char* testFilePath, const char* queryFilePath, graphNode_t *start, graphNode_t* end, AdjacencyListNode** ptr) {
    FILE *queryFile = fopen(queryFilePath, "r");
    if (!queryFile) {
        perror("invalid file path");
        return -1;
    }
    fscanf(queryFile, "%ld %ld", start, end);
    return adjMatrixToList(testFilePath, ptr);
}

// ****************
// Queue methods
// ****************

// free any queued graph nodes that we never visited because we already solved the maze
void freeQueue(Queue queue) {
    while ( queue.front ) {
        dequeue(&queue);
    }
}

// Increase readability
Queue newQueue() {
    Queue queue = { .front=NULL, .back=NULL };
    return queue;
}

// Append a new QueueNode to the back of the Queue
Queue enqueue ( struct Queue queue, graphNode_t graphNode ) {
    QueueNode *qNode = malloc(sizeof(QueueNode));
    qNode->graphNode = graphNode;
    qNode->next = NULL;
    if (queue.back == NULL) {
        queue.back = queue.front = qNode;
    } else {
        queue.back->next = qNode;
        queue.back = qNode;
    }
    return queue;
}

// Remove a QueueNode from the front of the Queue
graphNode_t dequeue ( Queue* queue ) {
    if (queue->front == NULL) return -1;
    QueueNode *topNode = queue->front;
    graphNode_t topVal = topNode->graphNode;
    queue->front = (queue->front)->next;
    if (!queue->front) queue->back = NULL;
    free(topNode);
    return topVal;
}

// ****************
// Work methods
// ****************
graphNode_t *BFS(AdjacencyListNode *adjList, graphNode_t start, graphNode_t end, size_t len) {
    Queue q = newQueue();
    graphNode_t* parents = initParents(len);
    q = enqueue(q, start);
    parents[start] = start;
    graphNode_t top;
    while (q.front) {
        top = dequeue(&q);
        q = processNeighbors(q, adjList[top].next, top, parents);
    }
    freeQueue(q);
    return parents;
}

Queue processNeighbors(Queue q, AdjacencyListNode* ptr, graphNode_t parent, graphNode_t *parents) {
    while (ptr) {
        graphNode_t child = ptr->graphNode;
        if (parents[child] == -1) {
            q = enqueue(q, child);
            parents[child] = parent;
        }
        ptr = ptr->next;
    }
    return q;
}

void printPath(size_t len, graphNode_t parents[len], graphNode_t start, graphNode_t end) {
    size_t i = end;
    while (i != start) {
        printf("%ld %ld\n", parents[i], i);
        i = parents[i];
    }
    puts("");
}

graphNode_t *initParents(size_t N) {
    graphNode_t* parents = calloc( N, sizeof(graphNode_t) );
    for (size_t i=0; i<N; i++) {
        parents[i] = -1; // -1 indicates that a nodes is not yet visited
    }
    return parents;
}

// Debugging method
void printQ(QueueNode *front) {
    while (front) {
        printf("%ld -> ", front->graphNode);
        front = front->next;
    }
    puts("");
}
