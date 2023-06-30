
// 💡 **Question 3**

// Given an integer array nums sorted in **non-decreasing** order, return *an array of **the squares of each number** sorted in non-decreasing order*.

// **Example 1:**

// **Input:** nums = [-4,-1,0,3,10]

// **Output:** [0,1,9,16,100]

// **Explanation:** After squaring, the array becomes [16,1,0,9,100].

// After sorting, it becomes [0,1,9,16,100].


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Question 3: Squares of each number in non-decreasing order
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    int left = 0;
    int right = numsSize - 1;
    int index = numsSize - 1;

    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare) {
            result[index] = leftSquare;
            left++;
        } else {
            result[index] = rightSquare;
            right--;
        }

        index--;
    }

    return result;
}

int main(){
    int nums[] = {-4, -1, 0, 3, 10};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* squared = sortedSquares(nums, numsSize, &returnSize);

    printf("Question 3: Squares of each number sorted in non-decreasing order:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", squared[i]);
    }
    printf("\n\n");
    free(squared);}