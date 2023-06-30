// <aside>
// 💡 **Question 6**

// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears **once** or **twice**, return *an array of all the integers that appears **twice***.

// You must write an algorithm that runs in O(n) time and uses only constant extra space.

// **Example 1:**

// **Input:** nums = [4,3,2,7,8,2,3,1]

// **Output:**

// [2,3]
#include <stdio.h>

int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int* duplicates = (int*)malloc(numsSize * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0) {
            duplicates[(*returnSize)++] = abs(nums[i]);
        } else {
            nums[index] = -nums[index];
        }
    }

    return duplicates;
}

int main() {
    int nums[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* duplicates = findDuplicates(nums, numsSize, &returnSize);

    printf("Duplicates: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", duplicates[i]);
    }
    printf("\n");

    free(duplicates);

    return 0;
}
