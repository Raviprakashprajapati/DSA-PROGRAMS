
// 💡 **Question 1**
// Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2),..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

// **Example 1:**
// Input: nums = [1,4,3,2]
// Output: 4

// **Explanation:** All possible pairings (ignoring the ordering of elements) are:

// 1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
// 2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
// 3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
// So the maximum possible sum is 4

void sort(int *arr,int size){

    for (int i = 1; i < size; i++)
    {
        int swap = 0;
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = 1;
            }
        }
        // already sorted
        if (swap == 0)
        {
            break;
        }
    }
    

}

int compare(int *arr,int size){

    sort(arr,size);

    int sum = 0;
    for (int i = 0; i <size; i++)
    {
        sum+=arr[i];
    }

    return sum;
    
    
}


#include <stdio.h>
int main()
{
    int arr[] = {1, 4, 3, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxSum = compare(arr,size);

    printf("Maximum sum is = %d",maxSum);

    return 0;
}