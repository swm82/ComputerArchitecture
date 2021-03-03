# 2. isTree: Determining whether an undirected graph is a tree using depth-first search (medium) (22 points)
An undirected graph is a tree if and only if the graph contains no cycles. For example, this is a tree because it contains no cycles:

An undirected graph that is a tree.

While this graph contains cycles and therefore is not a tree:

An undirected graph that is not a tree.

In this second part of the assignment, you will write a depth-first search through a graph to determine whether the graph contains cycle. A cycle is detected when depth-first search find a graph node that was already visited.

Input format
Your program should take a single command line argument specifying the path to an input file. Test cases for your program are in the tests/ directory. In each test case, the first line records the number of nodes N in the graph. Then, the adjacency matrix is recorded in the subsequent N rows of the file.

Output format
You should print "yes" if the graph is a tree, "no" if the graph is not a tree. Expected outputs from your program for each test case are in the answers/ directory.
