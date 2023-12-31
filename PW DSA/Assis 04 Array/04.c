// <aside>
// 💡 **Question 4**
// Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is **maximized**. Return *the maximized sum*.

// **Example 1:**

// Input: nums = [1,4,3,2]

// Output: 4

// **Explanation:** All possible pairings (ignoring the ordering of elements) are:

// 1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3

// 2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3

// 3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4

// So the maximum possible sum is 4.


#include <stdio.h>

int arrayPairSum(int nums[], int size) {

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (nums[i] > nums[j]) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }

    int sum = 0;
 
    for (int i = 0; i < size; i += 2) {
        sum += nums[i];
    }

    return sum;
}

int main() {
    int nums[] = {1, 4, 3, 2};
    int size = sizeof(nums) / sizeof(nums[0]);

    int maxSum = arrayPairSum(nums, size);

    printf("Output: %d\n", maxSum);

    return 0;
}
