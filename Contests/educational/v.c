#include<stdio.h>
void swap(int *a,int *b){
 int temp = *a;
 *a = *b;
 *b = temp;
}
int main(){
 int n,i,j;
 printf("Enter the size of the array\n");
 scanf("%d",&n);
 int arr[n];
 printf("Enter the elements of the array\n");
 for(i=0;i<n;i++){
  scanf("%d",&arr[i]);
 }
 printf("The given array is\n");
 for(i=0;i<n;i++){
  printf("%d ",arr[i]);
 }
 printf("\n");
 for(i=0;i<n;i++){
  int mn=__INT_MAX__;
  int idx = -1;
  for(j=i;j<n;j++){
   if(arr[j] < mn){
    mn = arr[j];
    idx = j;
   }
  }
  swap(&arr[i],&arr[idx]);
 }
 printf("Sorted array is\n");
 for(int i=0;i<n;i++){
  printf("%d ",arr[i]);
 }
 return 0;
}
