
// 💡 **Q5.** You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
// **Example 1:**
// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// **Explanation:** The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1

#include <stdio.h>

void merge(int *num1, int *num2, int m, int n)
{
    int end1 = m - 1;
    int end2 = n - 1;
    int full = m + n - 1;
    while (end1 >= 0 && end2 >= 0)
    {
        if (num1[end1] > num2[end2])
        {
            num1[full--] = num1[end1--];
        }
        else
        {
            num1[full--] = num2[end2--];
        }
    }

    while (end2 >= 0)
    {
        num1[full--] = num2[end2--];
    }
}

int main()
{
    int num1[6] = {1, 2, 3,0,0,0};
    int num2[] = {2, 5, 89};
    int m = 3;
    int n = sizeof(num2) / sizeof(num2[0]);

    merge(num1, num2, m, n);
    printf("After merge\n");

    for (int i = 0; i < m + n; i++)
    {
        printf("%d  ", num1[i]);
    }

    return 0;
}