#define in(x) scanf("%d",&x)
#define out(x) printf("%d",x)
#include<stdio.h>
void pr(int temp[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d ",temp[i]);
    }
}
int main(){
    int a[] = {1,2,3};
    int size = sizeof(a) / sizeof(a[0]);
    pr(a,size);
}
