#include<stdio.h>
int Factorial(int);
int main(){
    printf("Enter the no: \n");
    int a;
    scanf("%d",&a);
    int f;
    f=Factorial(a);
    printf("%d",f);
    return 0;
}
int Factorial(int n){
    int fact;
    if(n==1)
    return 1;
    fact = n * Factorial(n-1);
    return fact; 
}