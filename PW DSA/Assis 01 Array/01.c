
//  **Q1.** Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

// **Example:**
// Input: nums = [2,7,11,15], target = 9
// Output0 [0,1]

// **Explanation:** Because nums[0] + nums[1] == 9, we return [0, 1][






#include <stdio.h>
int main()
{
    int arr[] = {2,7,11,15,20};
    int target, i, j;
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("size of array = %d\n",size);
    printf("Enter target value: ");
    scanf("%d", &target);

    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[i]!=arr[j])
            {
                if (arr[i] + arr[j] == target)
            {
                printf("[%d][%d]\n", i, j);
                printf("%d + %d = %d\n", arr[i], arr[j], target);
                return 0;
            }
            }
            
        }
    }

    printf("No two elements sum up to the target value.\n");
    return 0;
}
