
// 💡 **Q2.** Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
// Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

// - Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
// - Return k.

// **Example :**
// Input: nums = [3,2,2,3], val = 3
// Output: 2, nums = [2,2,_*,_*]

// **Explanation:** Your function should return k = 2, with the first two elements of nums being 2. It does not matter what you leave beyond the returned k (hence they are underscores)[


#include<stdio.h>
int deleteElement(int *arr,int size,int value)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i]!=value)
        {
            arr[count] = arr[i];
            count++; 
        }

        
    }
    return count;
    
}

int main()
{
    int arr[] = {52,10,10,15,10,1,6151};
    int size = sizeof(arr)/sizeof(arr[0]);
    int Deletevalue = 10;
    int count = deleteElement(arr,size,Deletevalue);
    printf("Remainning Elements Count = %d\n",count);
    printf("Remainning Elements - ");
    for (int i = 0; i < count; i++)
    {
        printf("%d  ",arr[i]);
    }
    






return 0;
}