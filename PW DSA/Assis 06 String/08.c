// <aside>
// 💡 **Question 8**

// Given two [sparse matrices](https://en.wikipedia.org/wiki/Sparse_matrix) mat1 of size m x k and mat2 of size k x n, return the result of mat1 x mat2. You may assume that multiplication is always possible.

// **Example 1:**

// **Input:** mat1 = [[1,0,0],[-1,0,3]], mat2 = [[7,0,0],[0,0,0],[0,0,1]]

// **Output:**

// [[7,0,0],[-7,0,3]]

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int val;
} SparseElement;

typedef struct {
    int row;
    int col;
    int count;
    SparseElement* elements;
} SparseMatrix;

SparseMatrix createSparseMatrix(int** matrix, int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    
    SparseMatrix sparseMatrix;
    sparseMatrix.row = rows;
    sparseMatrix.col = cols;
    sparseMatrix.count = count;
    sparseMatrix.elements = (SparseElement*)malloc(count * sizeof(SparseElement));
    
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix.elements[index].row = i;
                sparseMatrix.elements[index].col = j;
                sparseMatrix.elements[index].val = matrix[i][j];
                index++;
            }
        }
    }
    
    return sparseMatrix;
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** multiplySparseMatrices(SparseMatrix mat1, SparseMatrix mat2) {
    int** result = (int**)malloc(mat1.row * sizeof(int*));
    for (int i = 0; i < mat1.row; i++) {
        result[i] = (int*)calloc(mat2.col, sizeof(int));
    }
    
    for (int i = 0; i < mat1.count; i++) {
        int row1 = mat1.elements[i].row;
        int col1 = mat1.elements[i].col;
        int val1 = mat1.elements[i].val;
        
        for (int j = 0; j < mat2.count; j++) {
            int row2 = mat2.elements[j].row;
            int col2 = mat2.elements[j].col;
            int val2 = mat2.elements[j].val;
            
            if (col1 == row2) {
                result[row1][col2] += val1 * val2;
            }
        }
    }
    
    return result;
}

int main() {
    int mat1Rows = 2;
    int mat1Cols = 3;
    int mat1Data[][3] = {
        {1, 0, 0},
        {-1, 0, 3}
    };
    
    int mat2Rows = 3;
    int mat2Cols = 3;
    int mat2Data[][3] = {
        {7, 0, 0},
        {0, 0, 0},
        {0, 0, 1}
    };
    
    int** mat1 = (int**)malloc(mat1Rows * sizeof(int*));
    for (int i = 0; i < mat1Rows; i++) {
        mat1[i] = (int*)malloc(mat1Cols * sizeof(int));
       int j = 0; j < mat1Cols; j++) {
            mat1[i][j] = mat1Data[i][j];
        }
    }
    
    int** mat2 = (int**)malloc(mat2Rows * sizeof(int*));
    for (int i = 0; i < mat2Rows; i++) {
        mat2[i] = (int*)malloc(mat2Cols * sizeof(int));
        for (int j = 0; j < mat2Cols; j++) {
            mat2[i][j] = mat2Data[i][j];
        }
    }
    
    printf("Matrix 1:\n");
    printMatrix(mat1, mat1Rows, mat1Cols);
    
    printf("\nMatrix 2:\n");
    printMatrix(mat2, mat2Rows, mat2Cols);
    
    SparseMatrix sparseMat1 = createSparseMatrix(mat1, mat1Rows, mat1Cols);
    SparseMatrix sparseMat2 = createSparseMatrix(mat2, mat2Rows, mat2Cols);
    
    int** result = multiplySparseMatrices(sparseMat1, sparseMat2);
    
    printf("\nResult Matrix:\n");
    printMatrix(result, mat1Rows, mat2Cols);
    
    // Free memory
    for (int i = 0; i < mat1Rows; i++) {
        free(mat1[i]);
    }
    free(mat1);
    
    for (int i = 0; i < mat2Rows; i++) {
        free(mat2[i]);
    }
    free(mat2);
    
    for (int i = 0; i < mat1Rows; i++) {
        free(result[i]);
    }
    free(result);
    
    free(sparseMat1.elements);
    free(sparseMat2.elements);
    
    return 0;
}

