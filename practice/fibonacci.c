#include<stdio.h>
int fibonacci(int);
int main(){
    printf("Enter the position of no in fibonacci series which is to be find:\n");
    int position;
    scanf("%d",&position);
    for(int i=1;i<=position;i++)
    printf("%d ",fibonacci(i));
    return 0;
}
int fibonacci(int n){
    if(n==1||n==2)
    return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}