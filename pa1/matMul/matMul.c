#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

FILE *openFile(char *filename);
int readDimension(FILE *fp);
void readMatrix(int **matrix, int rows, int cols, FILE* fp);
void createMatrix(int*** matrix, char rows, char cols);
void freeMatrix(int** matrix, int rows);
int multMatrix(int **a, int **b, int **result, int m, int n, int p, int q);
void printMatrix(int **matrix, int rows, int cols);

int main(int argc, char* argv[])
{
    // Read matrix A
    FILE *matrix_a_fp;
    if (!(matrix_a_fp = openFile(argv[1]))) return EXIT_FAILURE;
    char length_m = readDimension(matrix_a_fp);
    char length_n = readDimension(matrix_a_fp);
    int ** matrix_a;
    createMatrix(&matrix_a, length_m, length_n);
    readMatrix(matrix_a, length_m, length_n, matrix_a_fp);
    fclose(matrix_a_fp);
    
    // Read matrix B
    FILE *matrix_b_fp;
    if (!(matrix_b_fp = openFile(argv[2]))) return EXIT_FAILURE;
    char length_p = readDimension(matrix_b_fp);
    char length_q = readDimension(matrix_b_fp);
    int ** matrix_b;
    createMatrix(&matrix_b, length_p, length_q);
    readMatrix(matrix_b, length_p, length_q, matrix_b_fp);
    fclose(matrix_b_fp);

    // Multiply matrices
    int ** matrix_result;
    createMatrix(&matrix_result, length_m, length_q);
    if (!multMatrix(matrix_a, matrix_b, matrix_result, length_m, length_n, length_p, length_q)) return EXIT_FAILURE;
    printMatrix(matrix_result, length_m, length_q);

    // Free matrices
    freeMatrix(matrix_a, length_m);
    freeMatrix(matrix_b, length_p);
    freeMatrix(matrix_result, length_m);

    return EXIT_SUCCESS;
}

int readDimension(FILE *fp) {
    char buff[256];
    fscanf(fp, "%s", buff);
    return atoi(buff);
}

FILE *openFile(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("fopen failed");
        return NULL;
    }
    return fp;
}

void freeMatrix(int** matrix, int rows) {
    for ( unsigned char i=0; i<rows; i++ ) {
        free( matrix[i] );
    }
    free( matrix );
}

void createMatrix(int*** matrix, char rows, char cols) {
    *matrix = malloc( rows * sizeof(int*) );
    for ( unsigned char i=0; i<rows; i++ ) {
        (*matrix)[i] = malloc( cols * sizeof(int) );
    }
}

void readMatrix(int **matrix, int rows, int cols, FILE* fp) {
    char buff[256];
    for (unsigned char i = 0; i < rows; i++) {
        for (unsigned char j = 0; j < cols; j++) {
            fscanf(fp, "%s", buff);
            int num = atoi(buff);
            matrix[i][j] = num;
        }
    }
}

// Multiply matrices, if dimensions not compatible, return false (0)
int multMatrix(int **a, int **b, int **result, int m, int n, int p, int q) {
    assert(n == p);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
    return 1;
}

void printMatrix(int **matrix, int rows, int cols) {
    for (unsigned char i = 0; i < rows; i++) {
        for (unsigned char j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
    }
}
