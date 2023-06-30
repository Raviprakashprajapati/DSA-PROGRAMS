// <aside>
// 💡 **Question 1**

// Convert 1D Array Into 2D Array

// You are given a **0-indexed** 1-dimensional (1D) integer array original, and two integers, m and n. You are tasked with creating a 2-dimensional (2D) array with  m rows and n columns using **all** the elements from original.

// The elements from indices 0 to n - 1 (**inclusive**) of original should form the first row of the constructed 2D array, the elements from indices n to 2 * n - 1 (**inclusive**) should form the second row of the constructed 2D array, and so on.

// Return *an* m x n *2D array constructed according to the above procedure, or an empty 2D array if it is impossible*.

// **Example 1:**

// </aside>
// **Input:** original = [1,2,3,4], m = 2, n = 2

// **Output:** [[1,2],[3,4]]

// **Explanation:** The constructed 2D array should contain 2 rows and 2 columns.

// The first group of n=2 elements in original, [1,2], becomes the first row in the constructed 2D array.

// The second group of n=2 elements in original, [3,4], becomes the second row in the constructed 2D array.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int original[] = {1, 2, 3, 4};
    int m = 2;  // Number of rows
    int n = 2;  // Number of columns

    int originalSize = sizeof(original) / sizeof(original[0]);
    int expectedSize = m * n;

    if (originalSize != expectedSize) {
        printf("It is impossible to construct a %dx%d 2D array from the given 1D array.\n", m, n);
        return 0;
    }

    int** result = (int**)malloc(m * sizeof(int*));  // Allocate memory for rows

    for (int i = 0; i < m; i++) {
        result[i] = (int*)malloc(n * sizeof(int));  // Allocate memory for columns
    }

    int index = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = original[index++];
        }
    }

    printf("Constructed 2D array:\n");

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free dynamically allocated memory
    for (int i = 0; i < m; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}
