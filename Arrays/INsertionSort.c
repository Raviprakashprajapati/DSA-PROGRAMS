#include<stdio.h>
int main()
{
    int arr[] = {234,24,25,435,3,6};
    int size = sizeof(arr)/sizeof(arr[0]);

    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j  = i-1;

        for (; j>=0; j--)
        {
            if (temp<arr[j])
            {
                arr[j+1] = arr[j];
                
            }
            else{
                break;
            }
            
        }

        arr[j+1] = temp;
        
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d  ",arr[i]);
    }
    
    
    




return 0;
}