#include<stdio.h>
int count=0;
void tower(int,char,char,char);
int main(){
    int n;
    printf("Enter the no of disc's:\n");
    scanf("%d",&n);
    tower(n,'A','B','C');
    printf("Total no of cases are: %d",count);
    return 0;
}
void tower(int n,char S,char I,char T){
    if(n==1){
        printf("%c-->%c\n",S,T);
        count++;
        return;
    }
    tower(n-1,S,T,I);
    tower(1,S,I,T);
    tower(n-1,I,S,T);
}