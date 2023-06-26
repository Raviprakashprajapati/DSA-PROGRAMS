// Question 6
// Given an array of integers nums which is sorted in ascending order, and an integer target,
// write a function to search target in nums. If target exists, then return its index. Otherwise,
// return -1.

// You must write an algorithm with O(log n) runtime complexity.

// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4

// Explanation: 9 exists in nums and its index is 4
#include<stdio.h>

int search(int *arr,int size,int value){
    int beg = 0;
    int end = size-1;

    int mid = (beg+end)/2;
    while (beg<=end)
    {
        if (arr[mid]==value)
        {
            return mid;
        }

        if (arr[mid]<value)
        {
            beg = mid-1;
        }
        else
        {
            end = mid+1;
        }

        mid = (beg+end)/2;
        
        
    }

    return -1;
    
}



int main()
{
    int arr[] = {22,33,44,55,66,77,88,99};
    int size = sizeof(arr)/sizeof(arr[0]);
    int n;
    printf("Enter the number to be search = ");
    scanf("%d",&n);
    
    int found = search(arr,size,n);

    if (found==-1)
    {
        printf("Element not in array");
    }
    else
    {
        printf("Element is at %d",found);
    }
    




return 0;
}