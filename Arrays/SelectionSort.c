#include<stdio.h>

void sort(int *arr,int size){

    int i,j,key;
    for ( i = 1; i < size; i++)
    {
        key = arr[i];
        j = i-1;

        while (j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        
    }
    



 
    
}



int main()
{

    int arr[] = {2,24,3,543,564,36,45,6,54,756};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Elements - ");
    sort(arr,size);
    printf("Elements - ");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ",arr[i]);
        
    }
    




return 0;
}