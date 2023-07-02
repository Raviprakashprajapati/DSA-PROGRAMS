// <aside>
// 💡 **Question 2**

// You are given an m x n integer matrix matrix with the following two properties:

// - Each row is sorted in non-decreasing order.
// - The first integer of each row is greater than the last integer of the previous row.

// Given an integer target, return true *if* target *is in* matrix *or* false *otherwise*.

// You must write a solution in O(log(m * n)) time complexity.

// **Example 1:**
// **Input:** matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3

// **Output:** true

#include <stdbool.h>
#include <stdio.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int rows = matrixSize;
    int cols = *matrixColSize;
    
    int left = 0, right = rows * cols - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int num = matrix[mid / cols][mid % cols];
        
        if (num == target) {
            return true;
        } else if (num < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return false;
}

int main() {
    int matrix[][4] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int matrixSize = sizeof(matrix) / sizeof(matrix[0]);
    int matrixColSize[] = {4, 4, 4};
    int target = 3;
    
    bool result = searchMatrix((int**)matrix, matrixSize, matrixColSize, target);
    
    printf("Output: %s\n", result ? "true" : "false");
    
    return 0;
}
