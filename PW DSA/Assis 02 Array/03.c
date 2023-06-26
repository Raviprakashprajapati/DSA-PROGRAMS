// Question 3
// We define a harmonious array as an array where the difference between its maximum value
// and its minimum value is exactly 1.

// Given an integer array nums, return the length of its longest harmonious subsequence
// among all its possible subsequences.

// A subsequence of an array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

// Example 1:
// Input: nums = [1,3,2,2,5,2,3,7]
// Output: 5

// Explanation: The longest harmonious subsequence is [3,2,2,2,3].

#include <stdio.h>
#include <stdlib.h>

int findLHS(int* nums, int numsSize) {
    int maxLen = 0;
    int i, j;
    int* freqMap = (int*)malloc(sizeof(int) * 10001); 
    for (i = 0; i < 10001; i++) {
        freqMap[i] = 0;
    }
    
    for (i = 0; i < numsSize; i++) {
        freqMap[nums[i]]++;
    }
    for (i = 0; i < 10000; i++) {
        if (freqMap[i] > 0 && freqMap[i+1] > 0) {
            int len = freqMap[i] + freqMap[i+1];
            if (len > maxLen) {
                maxLen = len;
            }
        }
    }
    
    free(freqMap);
    return maxLen;
}

int main() {
    int nums[] = {1, 3, 2, 2, 5, 2, 3, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int longestSubsequence = findLHS(nums, numsSize);
    
    printf("The length of the longest harmonious subsequence is: %d\n", longestSubsequence);
    
    return 0;
}
