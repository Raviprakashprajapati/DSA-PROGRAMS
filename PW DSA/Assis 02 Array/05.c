// Question 5
// Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

// Example 1:
// Input: nums = [1,2,3]
// Output: 6

int max(int *arr, int size)
{

    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int product = 1;
    int count=1;
    for (int i =size-1; i >=0; i--)
    {
        if (count!=4)
        {
            
        product = product*arr[i];
        count++;
        }
        
    }

    return product;
    
}

#include <stdio.h>
int main()
{
    int arr[] = {3,9,6,43,5,6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = max(arr, size);
    printf("Max product will be %d ", result);

    return 0;
}