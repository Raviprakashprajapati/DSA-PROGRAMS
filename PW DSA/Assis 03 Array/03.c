// <aside>
// 💡 A permutation of an array of integers is an arrangement of its members into a
// sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr:
// [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

// The next permutation of an array of integers is the next lexicographically greater
// permutation of its integer. More formally, if all the permutations of the array are
// sorted in one container according to their lexicographical order, then the next
// permutation of that array is the permutation that follows it in the sorted container.

// If such an arrangement is not possible, the array must be rearranged as the
// lowest possible order (i.e., sorted in ascending order).

// ● For example, the next permutation of arr = [1,2,3] is [1,3,2].
// ● Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// ● While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not
// have a lexicographical larger rearrangement.

// Given an array of integers nums, find the next permutation of nums.
// The replacement must be in place and use only constant extra memory.

// **Example 1:**
// Input: nums = [1,2,3]
// Output: [1,3,2]

// </aside>

#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int* nums, int start, int end) {
    while (start < end) {
        swap(&nums[start], &nums[end]);
        start++;
        end--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    int i = numsSize - 2;

    // Find the first decreasing element from the right
    while (i >= 0 && nums[i] >= nums[i + 1])
        i--;

    if (i >= 0) {
        // Find the smallest element larger than nums[i]
        int j = numsSize - 1;
        while (j >= 0 && nums[j] <= nums[i])
            j--;

        // Swap nums[i] and nums[j]
        swap(&nums[i], &nums[j]);
    }

    // Reverse the suffix starting from i+1
    reverse(nums, i + 1, numsSize - 1);
}

void printArray(int* nums, int numsSize) {
    printf("[");
    for (int i = 0; i < numsSize; i++) {
        printf("%d", nums[i]);
        if (i != numsSize - 1)
            printf(", ");
    }
    printf("]\n");
}

int main() {
    int nums[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    printf("Input: ");
    printArray(nums, numsSize);

    nextPermutation(nums, numsSize);

    printf("Output: ");
    printArray(nums, numsSize);

    return 0;
}
