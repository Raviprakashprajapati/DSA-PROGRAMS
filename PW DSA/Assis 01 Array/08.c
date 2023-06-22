
// 💡 **Q8.** You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

// You are given an integer array nums representing the data status of this set after the error.

// Find the number that occurs twice and the number that is missing and return them in the form of an array.

// **Example 1:**
// Input: nums = [1,2,2,4]
// Output: [2,3]

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int arr[] = {1, 2, 3, 4, 5,3,7,8,9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int twice = 0;
    int value = 0;
    int n = 1;
    int *ptr = malloc(2 * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != n++)
        {
            ptr[0] = arr[i];
            ptr[1] = n - 1;
            break;
        }
    }
    printf("Element occurs twice = %d\n",ptr[0]);
    printf("Missing number = %d\n",ptr[1]);
   
    free(ptr);

    return 0;
}

