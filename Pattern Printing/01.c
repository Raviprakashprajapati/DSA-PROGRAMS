#include<stdio.h>

int main(){
    int n;
    printf("Enter the number = ");
    scanf("%d",&n);

    int i = 1;
    while (i<=n)
    {
        int j = 1;
        
        while (j<=n)
        {
            printf(" * ");
            j++;
        }
        printf("\n");
        i++;
        
    }
    

}