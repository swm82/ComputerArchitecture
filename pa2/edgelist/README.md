# 1. edgelist: Loading, representing, and printing an undirected unweighted graph (easy) (22 points)
Graphs are fundamental data structures. A graph consists of nodes and edges connecting pairs of nodes. A basic kind of graph is an undirected, unweighted graph, meaning that the edges are not directional, and each edge doesn't have any additional properties. Here is an example of an undirected, unweighted graph G=(V,E), V={0,1,2,3}, E={(0,1),(0,2),(0,3),(1,3)} of four nodes and four edges:

An undirected, unweighted graph of four nodes and four edges.

There are several important ways to represent graphs.

The first graph representation is an adjacency matrix (Links to an external site.). The adjacency matrix of the above graph is:
```
0 1 1 1 
1 0 0 1 
1 0 0 0 
1 1 0 0
```

The 0, 1, 1, 1 in the first row of the matrix indicates the 0th node is connected to the 1st, 2nd, and 3rd nodes, and so on.

The second graph representation is an adjacency list (Links to an external site.). For a graph consisting of N nodes, the adjacency list data structure is an array of N separate linked lists for each node p, where each link in the linked list records a node q if the edge (p,q) exists. For example, the adjacency list representation of the above graph is:
```
0->1->2->3->/
1->0->3->/
2->0->/
3->0->1->/
```

The ->/ indicates a null pointer terminating the linked list.

The third graph representation is by listing the edges of the graph. For example, the edge list of the above graph is:
```
0 2
0 3
0 1
1 3
```

In the first part of this assignment, you will write a program that:

Loads an adjacency matrix representation of an undirected unweighted graph,
Holds that graph representation as a adjacency list data structure,
Prints out the edge list representation of the graph.
Input format
Your program should take a single command line argument specifying the path to an input file. Test cases for your program are in the tests/ directory. In each test case, the first line records the number of nodes N in the graph. Then, the adjacency matrix is recorded in the subsequent N rows of the file.

Output format
Expected outputs from your program for each test case are in the answers/ directory. You should print one line for each edge of the graph; each line should list the pair of nodes (separated by a space) constituting a graph edge.

This is an undirected graph, so the order of the nodes does not matter. The autograder will recognize re-ordering of the nodes as correct. The ordering of which edges are printed first also does not matter. The autograder will recognize re-ordering of the edges as correct.


