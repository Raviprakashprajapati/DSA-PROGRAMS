// Question 8
// You are given an integer array nums and an integer k.

// In one operation, you can choose any index i where 0 <= i < nums.length and change nums[i] to nums[i] + x where x is an integer from the range [-k, k]. You can apply this operation at most once for each index i.

// The score of nums is the difference between the maximum and minimum elements in nums.

// Return the minimum score of nums after applying the mentioned operation at most once for each index in it.

// Example 1:
// Input: nums = [1], k = 0
// Output: 0

// Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.


int minScore(int *arr,int size,int k){
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i]>max)
        {
            max = arr[i];
        }
        if (arr[i]<min)
        {
            min = arr[i];
        }
        
        
    }
    int newMin = min+k;
    int newMax = max-k;

    return (newMax<=newMin)?0:(newMax-newMin);

    
}

#include<stdio.h>
int main()
{
    int arr[]={1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k= 0;

    int result = minScore(arr,size,k);
    printf("minimum score of arr %d",result);




return 0;
}