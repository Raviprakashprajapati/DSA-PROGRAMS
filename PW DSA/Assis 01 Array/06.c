
// 💡 **Q6.** Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

// **Example 1:**
// Input: nums = [1,2,3,1]

// Output: true

#include<stdio.h>
int main()
{
    int arr[] = {1,2,3,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int found = 0;
    for (int i = 0; i < size; i++)
    {
        int value = arr[i];

        for (int j = i+1; j<size; j++)
        {
            if (arr[j]==value)
            {
                found = 1;
                break;
            }
            
        }
        
    }

    if (found==1)
    {
        printf("TRUE");
    }
    else { printf("FALSE"); }
    
    




return 0;
}