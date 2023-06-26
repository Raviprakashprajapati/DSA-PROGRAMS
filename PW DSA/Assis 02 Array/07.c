// An array is monotonic if it is either monotone increasing or monotone decreasing.

// An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is
// monotone decreasing if for all i <= j, nums[i] >= nums[j].

// Given an integer array nums, return true if the given array is monotonic, or false otherwise.

// Example 1:
// Input: nums = [1,2,2,3]
// Output: true

int check(int *arr,int size){
    int increase = 1;
    int decrease = 1;
    for (int i = 1; i < size; i++)
    {
        if (arr[i]<arr[i-1])
        {
            increase=0;
        }
        
        if (arr[i]>arr[i-1])
        {
            decrease=0;
        }
        
        
    }

    return increase || decrease;
    
    
}




#include<stdio.h>
int main()
{

    int arr[] = {1,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);

    int result = check(arr,size);
    if (result)
    {
        printf("monotonic increase");
        
    }
    else
    {
        printf("not monotnic incraese");
    }
    




return 0;
}