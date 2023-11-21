#include<iostream>
using namespace std;

int factorial(int n){
    // if(n==0) return 1;

    return n*factorial(n-1);
}

int fibonacci(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}

void armstrong(int n){
    int sum = 0;
    int temp = n;
    while(temp!=0){
        int last = temp%10;
        sum = sum+last*last*last;
        temp = temp/10;
    }
    if(sum==n){ cout<<"armstrong"; return; }
    cout<<"not armstrong";


}

void palindrome(int n){
    int temp = n;
    int sum = 0;
    while(temp!=0){
        int last = temp%10;
        sum = sum*10 + last;
        temp = temp/10;
    }
    if(sum==n){ cout<<"palindrome"; return; }
    cout<<"not palindrome";
 
}

int main(){
    int n;
    cout<<"Enter number  = ";
    cin>>n;

    // cout<<factorial(n);
    // cout<<fibonacci(n);
    // armstrong(n);
    palindrome(n);
    
}

