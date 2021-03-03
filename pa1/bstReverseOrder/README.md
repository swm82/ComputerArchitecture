# 5. bstReverseOrder: reverse order traversal of a binary search tree (22 points)
Your task in this part of the assignment is to write a C program that constructs a binary search tree from a list of input numbers, and then print out the binary search tree in a reverse order traversal of the tree. You may find it helpful to review the properties of a binary search tree, and the various flavors of tree traversal order. In a binary search tree, the key in each node is greater than all keys in its left subtree, and is lesser than all keys in its right subtree.

Your program should take as a command line input the path to an input file:

```./bstBreadthFirst tests/test0.txt```

Each line of the input file lists a number to be inserted into the binary search tree. If a number has already been inserted, you can ignore the duplicate insertion. Since we are not performing tree balancing, everyone should arrive at the same binary search tree structure for any given input sequence. For example, an input sequence of 8,3,6,1,10,4,14,7,13 would lead to this unique binary search tree (image credit wikimedia):

Binary_search_tree.svg

Once the binary search tree is constructed, your program should print out the nodes in a depth-first, reverse in-order traversal of the tree. That is, for every node you visit, you should visit the right subtree first, then print the root node, and finally visit the left subtree. A reverse order traversal of the example tree above would return the numbers in descending order: 14, 13, 10, 8, 7, 6, 4, 3, 1.

The corresponding expected outputs are in the answers directory: answers/answer0.txt.
