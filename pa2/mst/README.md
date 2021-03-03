4. mst: Finding the minimum spanning tree of a undirected weighted graph (medium) (22 points)
A weighted graph is a graph that has a numerical weight property on each edge. The minimum spanning tree (MST) of an undirected weighted graph is a tree that connects all nodes in the graph, and at the same time minimizing the sum of the weights of the tree's edges. Many important problems in computer networking and operations research boil down to finding MSTs on graphs. As an example, this is a undirected weighted graph:

An undirected weighted graph.

And this is its MST:

The minimum spanning tree of an undirected weighted graph.

The edges (0,1) and (1,2) connects all nodes in the graph, and picking these edges minimizes the total weight of the tree. If all the weights in an undirected weighted graph are unique, then the MST is also unique, meaning everyone will find the same MST for a given graph.

In this fourth part of the assignment, you will write a program implementing a greedy algorithm to find the MST. Several algorithms solve this problem, but Prim's algorithm (Links to an external site.) is likely the easiest to implement.

Input format
Your program should take a single command line argument specifying the path to an input file. Test cases for your program are in the tests/ directory. In each test case, the first line records the number of nodes N in the graph. Then, the adjacency matrix is recorded in the subsequent N rows of the file. This time, the adjacency matrix contains floating point numbers. 0.0 indicates no edge between two nodes. Any other value indicates an edge with the given value as the edge weight.

Output format
Expected outputs from your program for each test case are in the answers/ directory. You should print a list of edges that, taken together, form the MST of the input graph. Again, the ordering of the nodes in each edge does not matter. The ordering of the edges does not matter. 
