// <aside>
// 💡 **Question 5**

// The **product sum** of two equal-length arrays a and b is equal to the sum of a[i] * b[i] for all 0 <= i < a.length (**0-indexed**).

// - For example, if a = [1,2,3,4] and b = [5,2,3,1], the **product sum** would be 1*5 + 2*2 + 3*3 + 4*1 = 22.

// Given two arrays nums1 and nums2 of length n, return *the **minimum product sum** if you are allowed to **rearrange** the **order** of the elements in* nums1.

// **Example 1:**

// **Input:** nums1 = [5,3,4,2], nums2 = [4,2,2,5]

// **Output:** 40

// **Explanation:**

// We can rearrange nums1 to become [3,5,4,2]. The product sum of [3,5,4,2] and [4,2,2,5] is 3*4 + 5*2 + 4*2 + 2*5 = 40.


#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minProductSum(int* nums1, int* nums2, int numsSize) {
    qsort(nums1, numsSize, sizeof(int), compare);
    qsort(nums2, numsSize, sizeof(int), compare);
    
    int minProduct = 0;
    
    for (int i = 0; i < numsSize; i++) {
        minProduct += nums1[i] * nums2[numsSize - 1 - i];
    }
    
    return minProduct;
}

int main() {
    int nums1[] = {5, 3, 4, 2};
    int nums2[] = {4, 2, 2, 5};
    int numsSize = sizeof(nums1) / sizeof(nums1[0]);
    
    int result = minProductSum(nums1, nums2, numsSize);
    
    printf("Output: %d\n", result);
    
    return 0;
}
