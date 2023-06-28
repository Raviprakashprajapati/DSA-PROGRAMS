// Question 1
// Given an integer array nums of length n and an integer target, find three integers
// in nums such that the sum is closest to the target.
// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

// Example 1:
// Input: nums = [-1,2,1,-4], target = 1
// Output: 2

// // Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int threeSumClosest(int* nums, int numsSize, int target) {
    int closestSum = INT_MAX;
    int minDiff = INT_MAX;

    // Sort the array in ascending order
    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            int diff = abs(target - sum);

            // Check if the current sum is closer to the target
            if (diff < minDiff) {
                minDiff = diff;
                closestSum = sum;
            }

            if (sum < target)
                left++;
            else if (sum > target)
                right--;
            else
                return target;
        }
    }

    return closestSum;
}

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int nums[] = {-1, 2, 1, -4};
    int target = 1;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = threeSumClosest(nums, numsSize, target);
    printf("Closest sum to the target: %d\n", result);

    return 0;
}
