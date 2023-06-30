
// 💡 **Question 6**
// Given an integer array nums sorted in **non-decreasing** order, return *an array of **the squares of each number** sorted in non-decreasing order*.

// **Example 1:**

// Input: nums = [-4,-1,0,3,10]

// Output: [0,1,9,16,100]

// **Explanation:** After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100]

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    return num1 - num2;
}

int* sortedSquares(int* nums, int size, int* returnSize) {
    int* squares = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        squares[i] = nums[i] * nums[i];
    }
    qsort(squares, size, sizeof(int), compare);
    *returnSize = size;
    return squares;
}

int main() {
    int nums[] = {-4, -1, 0, 3, 10};
    int size = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* result = sortedSquares(nums, size, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i != returnSize - 1) {
            printf(",");
        }
    }
    printf("]\n");

    free(result);

    return 0;
}
