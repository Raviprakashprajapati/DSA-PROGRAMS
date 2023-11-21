#include <stdio.h>

void sort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int swap = 0;
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = 1;
            }
        }
        // already sorted
        if (swap == 0)
        {
            break;
        }
    }
}

int main()
{
    int arr[] = {245, 35, 346, 34, 564, 6, 3, 645, 7, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr, size);
    printf("Element - ");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}