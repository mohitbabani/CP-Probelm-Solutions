// MOHIT BABANI 
// 19ESKCS143
#include<stdio.h>
#define MAXN 100
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int search_number(int arr[],int left,int right,int x){
    if(right >= left){
        int mid = (left + right)/2;

        if(arr[mid] == x) return mid+1;

        if(arr[mid] > x) return search_number(arr,left,mid-1,x);

        return search_number(arr,mid+1,right,x);
    }

    return -1;
}
void selectionSort(int arr[],int n){
    int i, j, min_idx;
    for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}
int main(){
    int n,i,ans,x;
    int arr[MAXN];
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    selectionSort(arr,n);
    printf("Array sorted\n");
    printf("\nEnter the number you want to search\n");
    scanf("%d",&x);
    ans = search_number(arr,0,n-1,x);
    if(ans == -1) printf("%d was not found in the array\n",x);
    else printf("%d was found in array at index %d\n",x,ans);

    printf("\nProgram by MOHIT BABANI (19ESKCS143)\n");
    return 0;
}