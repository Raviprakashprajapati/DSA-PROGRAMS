
// 💡 **Question 4**

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
#include <stdlib.h>

int** findDisappearedNumbers(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int maxNum = 0;
    for (int i = 0; i < nums1Size; i++) {
        if (nums1[i] > maxNum) {
            maxNum = nums1[i];
        }
    }
    for (int i = 0; i < nums2Size; i++) {
        if (nums2[i] > maxNum) {
            maxNum = nums2[i];
        }
    }

    int* count1 = (int*)calloc(maxNum + 1, sizeof(int));
    int* count2 = (int*)calloc(maxNum + 1, sizeof(int));

    for (int i = 0; i < nums1Size; i++) {
        count1[nums1[i]] = 1;
    }

    for (int i = 0; i < nums2Size; i++) {
        count2[nums2[i]] = 1;
    }

    int count1Size = 0;
    int count2Size = 0;

    for (int i = 1; i <= maxNum; i++) {
        if (count1[i] == 0) {
            count1Size++;
        }
        if (count2[i] == 0) {
            count2Size++;
        }
    }

    int** result = (int**)malloc(2 * sizeof(int*));
    result[0] = (int*)malloc(count1Size * sizeof(int));
    result[1] = (int*)malloc(count2Size * sizeof(int));

    int resultIndex1 = 0;
    int resultIndex2 = 0;

    for (int i = 1; i <= maxNum; i++) {
        if (count1[i] == 0) {
            result[0][resultIndex1++] = i;
        }
        if (count2[i] == 0) {
            result[1][resultIndex2++] = i;
        }
    }

    *returnSize = 2;
    return result;
}

int main() {
    int nums1[] = {1, 2, 3};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);

    int nums2[] = {2, 4, 6};
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    int returnSize;
    int** result = findDisappearedNumbers(nums1, nums1Size, nums2, nums2Size, &returnSize);

    printf("Question 4: Distinct integers not present in the other array:\n");
    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < (i == 0 ? nums1Size : nums2Size); j++) {
            printf("%d", result[i][j]);
            if (j != (i == 0 ? nums1Size : nums2Size) - 1) {
                printf(",");
            }
        }
        printf("]");
    }
    printf("]\n");

    free(result[0]);
    free(result[1]);
    free(result);

    return 0;
}
