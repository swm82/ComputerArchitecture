# 3. matMul: matrix multiplication (22 points)
Matrix multiplication is a fundamental task in almost every area of computer science, including machine learning and solving scientific problems. You may wish to review the rules of matrix multiplication. Suppose matrix A has size L rows x M columns, matrix B has size M x N, then the matrix multiplication of the two matrices A x B = C, where matrix C has size L x N.

Your task is to write a C program that takes two command line inputs, indicating two files to load. The first file contains matrix A and the second file contains matrix B. For example:

```./matMul tests/matrix_a_0.txt tests/matrix_b_0.txt```

In both of these input files, the format is such that the first line contains the number of rows in the matrix, and the second line contains the number of columns in the matrix. Then, the file continues for several lines, each line corresponding to a row of the input matrix. In each row, the columns of the matrix are listed, each number separated by a space.

Your program should load these files and perform matrix multiplication of the two matrices. Then, your program should output L*N number of numbers reading out the elements of the product matrix C in row-major order: first print out the elements in the first row, separated by spaces, followed by printing the elements of the second row, and so forth.

The corresponding expected outputs are in the answers directory: e.g., answers/matrix_c_0.txt.
