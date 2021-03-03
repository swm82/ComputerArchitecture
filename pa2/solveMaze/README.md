# 3. solveMaze: Finding the shortest path through a maze with cycles using breadth-first search (hard) (22 points)
In this third part of the assignment, you will write a program to find a shortest path in a graph from a source node to a destination node using breadth-first search. The graph representing the maze may contain cycles, so it is important avoid revisiting nodes that have already been visited.

Many important problems in artificial intelligence, robotics motion planning, and self-driving cars boil down to solving mazes on graphs. In classes such as AI and robotics, you will learn about advanced algorithms for solving mazes using heuristics (or guesses) that minimize search time.

Input format
Your program should take TWO command line arguments. The first argument specifies the path to an input file describing a graph like previous portions of this assignment. The second argument specifies the path to an input file describing a query. The first line of the query file specifies the source node where you begin your search. The second line of the query file specifies the target node you want to reach.

Output format
You should print a list of edges that, taken together, connect the source node to the target node in the graph. Again, the ordering of the nodes in each edge does not matter. The ordering of the edges does not matter. The autograder will check to see if you give a minimal set of edges that connect the source and target nodes.
