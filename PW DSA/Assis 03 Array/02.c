// Question 2
// Given an array nums of n integers, return an array of all the unique quadruplets
// [nums[a], nums[b], nums[c], nums[d]] such that:
//            ● 0 <= a, b, c, d < n
//            ● a, b, c, and d are distinct.
//            ● nums[a] + nums[b] + nums[c] + nums[d] == target

// You may return the answer in any order.

// Example 1:
// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

#include <stdio.h>
#include <stdlib.h>

// Function to compare integers (used for sorting)
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void findQuadruplets(int* nums, int numsSize, int target) {
    // Sorting the input array
    qsort(nums, numsSize, sizeof(int), compare);

    int a, b, c, d, sum;

    // Fixing the first element and using three pointers to find the other three elements
    for (a = 0; a < numsSize - 3; a++) {
        if (a > 0 && nums[a] == nums[a - 1]) // Skip duplicates
            continue;

        for (b = a + 1; b < numsSize - 2; b++) {
            if (b > a + 1 && nums[b] == nums[b - 1]) // Skip duplicates
                continue;

            c = b + 1;
            d = numsSize - 1;

            while (c < d) {
                sum = nums[a] + nums[b] + nums[c] + nums[d];

                if (sum == target) {
                    // Found a quadruplet
                    printf("[%d, %d, %d, %d]\n", nums[a], nums[b], nums[c], nums[d]);

                    // Skip duplicates
                    while (c < d && nums[c] == nums[c + 1])
                        c++;
                    while (c < d && nums[d] == nums[d - 1])
                        d--;

                    c++;
                    d--;
                } else if (sum < target) {
                    c++; 
                } else {
                    d--; 
                }
            }
        }
    }
}

int main() {
    int nums[] = {1, 0, -1, 0, -2, 2};
    int target = 0;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    printf("Output: \n");
    findQuadruplets(nums, numsSize, target);

    return 0;
}
