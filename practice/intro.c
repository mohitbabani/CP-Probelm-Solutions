#include<stdio.h>
#include <cstdlib>
struct node{
    int info;
    struct node *next;
};
//Insertion 
//Deletion 
//Transversing
struct node *start;
start=NULL;
void insertion(){
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the info:\n");
    scanf("%d",&n->info);
    n->next=NULL;
    start=n;
}

int main(){
    insertion();
    return 0;
}