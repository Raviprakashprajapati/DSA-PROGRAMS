// Question 7
// You are given an inclusive range [lower, upper] and a sorted unique integer array
// nums, where all elements are within the inclusive range.

// A number x is considered missing if x is in the range [lower, upper] and x is not in
// nums.

// Return the shortest sorted list of ranges that exactly covers all the missing
// numbers. That is, no element of nums is included in any of the ranges, and each
// missing number is covered by one of the ranges.

// Example 1:
// Input: nums = [0,1,3,50,75], lower = 0, upper = 99
// Output: [[2,2],[4,49],[51,74],[76,99]]

// Explanation: The ranges are:
// [2,2]
// [4,49]
// [51,74]
// [76,99]



#include <stdio.h>
#include <stdlib.h>

char* formatRange(int start, int end) {
    char* range = (char*)malloc(20 * sizeof(char));
    if (start == end) {
        sprintf(range, "%d", start);
    } else {
        sprintf(range, "%d->%d", start, end);
    }
    return range;
}

char** findMissingRanges(int* nums, int numsSize, int lower, int upper, int* returnSize) {
    int capacity = 100;
    char** result = (char**)malloc(capacity * sizeof(char*));
    int count = 0;

    // Helper function to add range to the result
    void addRange(int start, int end) {
        if (count >= capacity) {
            capacity *= 2;
            result = (char**)realloc(result, capacity * sizeof(char*));
        }
        result[count++] = formatRange(start, end);
    }

    // Handle the case where lower is less than the first element in nums
    if (lower < nums[0]) {
        addRange(lower, nums[0] - 1);
    }

    // Handle the case between the elements in nums
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] != nums[i + 1] && nums[i] + 1 < nums[i + 1]) {
            addRange(nums[i] + 1, nums[i + 1] - 1);
        }
    }

    // Handle the case where upper is greater than the last element in nums
    if (upper > nums[numsSize - 1]) {
        addRange(nums[numsSize - 1] + 1, upper);
    }

    *returnSize = count;
    return result;
}

void printRanges(char** ranges, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%s", ranges[i]);
        if (i != size - 1)
            printf(", ");
    }
    printf("]\n");
}

int main() {
    int nums[] = {0, 1, 3, 50, 75};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int lower = 0;
    int upper = 99;

    int returnSize;
    char** result = findMissingRanges(nums, numsSize, lower, upper, &returnSize);

    printf("Output: ");
    printRanges(result, returnSize);

    // Free allocated memory
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}
