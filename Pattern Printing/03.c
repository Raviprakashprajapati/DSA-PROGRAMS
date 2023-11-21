#include<stdio.h>
int main(){
    int n;
    printf("Enter - ");
    scanf("%d",&n);
    int i=1;
    while (i<=n)
    {
        int j=1;
        while (j<=n)
        {
            printf(" %d ",n-j+1 );
            j++;
 
        }
        printf("\n");
        i++;
        
    }
    


// 12345
// 12345
// 12345
// 12345

}