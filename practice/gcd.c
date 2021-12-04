#include<stdio.h>
int GCD(int ,int);
int main(){
    printf("Enter two no:\n");
    int x1,x2;
    scanf("%d %d",&x1,&x2);
    printf("GreComDiv of %d and %d is %d",x1,x2,GCD(x1,x2));
    return 0;
}
int GCD(int n1,int n2){
    if(n1>n2){
        if(n1%n2==0)
        return n2;
        else 
        return GCD(n1%n2,n2);
    }
    else{
        if(n2%n1==0)
        return n1;
        else 
        return GCD(n1,n2%n1);
    }
}