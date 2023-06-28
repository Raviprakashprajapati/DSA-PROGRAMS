// Question 6
// Given a non-empty array of integers nums, every element appears twice except
// for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only
// constant extra space.

// Example 1:
// Input: nums = [2,2,1]
// Output: 1

#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int result = 0;

    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }

    return result;
}

int main() {
    int nums[] = {2, 2, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = singleNumber(nums, numsSize);

    printf("Output: %d\n", result);

    return 0;
}
