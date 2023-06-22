
// 💡 **Q7.** Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the nonzero elements.

// Note that you must do this in-place without making a copy of the array.
// **Example 1:**
// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]

#include<stdio.h>
int main()
{

    int arr[] = {0,1,0,3,12};
    int size = sizeof(arr)/sizeof(arr[0]);

    int index= 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i]!=0)
        {
            arr[index++] = arr[i];
        }
        
    }

    for (int i = index; i < size; i++)
    {
        arr[i] = 0;
    }
    

    printf("elements - ");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ",arr[i]);
    }
    
    





return 0;
}

