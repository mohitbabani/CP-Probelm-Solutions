#include<stdio.h>
int main(){
    int n,i,sum=0;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        sum += arr[i];
    }
    printf("Sum is  %d",sum);
}