
// 💡 **Question 4**

// Given a binary array nums, return *the maximum length of a contiguous subarray with an equal number of* 0 *and* 1.

// **Example 1:**

// **Input:** nums = [0,1]

// **Output:** 2

// **Explanation:**

// [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

#include <stdio.h>

int findMaxLength(int* nums, int numsSize) {
    int maxLength = 0;
    int count = 0;
    int* map = (int*)malloc((2 * numsSize + 1) * sizeof(int));
    
    for (int i = 0; i < 2 * numsSize + 1; i++) {
        map[i] = -2;
    }
    
    map[numsSize] = -1;
    
    for (int i = 0; i < numsSize; i++) {
        count += (nums[i] == 0) ? -1 : 1;
        
        if (map[count + numsSize] >= -1) {
            int length = i - map[count + numsSize];
            maxLength = (length > maxLength) ? length : maxLength;
        } else {
            map[count + numsSize] = i;
        }
    }
    
    free(map);
    
    return maxLength;
}

int main() {
    int nums[] = {0, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    int result = findMaxLength(nums, numsSize);
    
    printf("Output: %d\n", result);
    
    return 0;
}


