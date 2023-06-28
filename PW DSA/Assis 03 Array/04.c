// Question 4
// Given a sorted array of distinct integers and a target value, return the index if the
// target is found. If not, return the index where it would be if it were inserted in
// order.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [1,3,5,6], target = 5
// Output: 2

#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return left;
}

int main() {
    int nums[] = {1, 3, 5, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 5;

    int result = searchInsert(nums, numsSize, target);

    printf("Output: %d\n", result);

    return 0;
}
