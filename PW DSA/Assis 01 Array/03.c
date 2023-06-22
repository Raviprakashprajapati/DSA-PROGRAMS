
// 💡 **Q3.** Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// You must write an algorithm with O(log n) runtime complexity.
// **Example 1:**
// Input: nums = [1,3,5,6], target = 5
// Output: 2

#include <stdio.h>
int main()
{

    int arr[] = {1, 3, 5, 6, 20, 45, 67, 89};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 2;
    int beg = 0;
    int high = size - 1;
    while (beg <= high)
    {
    int mid = (beg + high) / 2;
        if (arr[mid] == target)
        {
            printf("Element found at %d", mid);
            break;
        }
        else if (arr[mid] < target)
        {
            beg = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    
    }

    return 0;
}