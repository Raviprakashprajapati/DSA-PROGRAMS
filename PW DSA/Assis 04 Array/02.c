
// 💡 **Question 2**

// Given two **0-indexed** integer arrays nums1 and nums2, return *a list* answer *of size* 2 *where:*

// - answer[0] *is a list of all **distinct** integers in* nums1 *which are **not** present in* nums2*.*
// - answer[1] *is a list of all **distinct** integers in* nums2 *which are **not** present in* nums1.

// **Note** that the integers in the lists may be returned in **any** order.

// **Example 1:**

// **Input:** nums1 = [1,2,3], nums2 = [2,4,6]

// **Output:** [[1,3],[4,6]]

// **Explanation:**

// For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].

// For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].



#include <stdio.h>

void findDistinctIntegers(int nums1[], int nums2[], int size1, int size2) {
    int distinctNums1[size1];
    int distinctNums2[size2];
    int count1 = 0, count2 = 0;

    for (int i = 0; i < size1; i++) {
        int isPresent = 0;
        for (int j = 0; j < size2; j++) {
            if (nums1[i] == nums2[j]) {
                isPresent = 1;
                break;
            }
        }
        if (!isPresent) {
            distinctNums1[count1] = nums1[i];
            count1++;
        }
    }
    for (int i = 0; i < size2; i++) {
        int isPresent = 0;
        for (int j = 0; j < size1; j++) {
            if (nums2[i] == nums1[j]) {
                isPresent = 1;
                break;
            }
        }
        if (!isPresent) {
            distinctNums2[count2] = nums2[i];
            count2++;
        }
    }

    printf("[");
    for (int i = 0; i < count1; i++) {
        printf("%d", distinctNums1[i]);
        if (i != count1 - 1)
            printf(",");
    }
    printf("], [");
    for (int i = 0; i < count2; i++) {
        printf("%d", distinctNums2[i]);
        if (i != count2 - 1)
            printf(",");
    }
    printf("]");
}

int main() {
    int nums1[] = {1, 2, 3};
    int nums2[] = {2, 4, 6};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int size2 = sizeof(nums2) / sizeof(nums2[0]);

    printf("Output: ");
    findDistinctIntegers(nums1, nums2, size1, size2);

    return 0;
}

