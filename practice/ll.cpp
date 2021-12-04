#include<stdio.h>
#include <cstdlib>

struct node{
    int info;
    struct node *link;
};
struct node *start=NULL;
struct node* createNode(){
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    return n;
}
void insertNode(){
    struct node *temp,*t;
    temp=createNode();
    printf("\nEnter the data of linked list: \n");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(start==NULL)
    start=temp;
    else{
        t=start;
        while (t->link!=NULL)
        t=t->link;
        t->link=temp;
    }
}
void deleteNode(){
    struct node *r;
    if(start==NULL)
    printf("List is empty\n");
    else{
        r=start;
        start=start->link;
        free(r);
    }
}
void viewList(){
    if(start==NULL)
    printf("List is empty\n");
    else{
        struct node *t=start;
        while(t!=NULL){
            printf("%d ",t->info);
            t=t->link;
        }
        printf("\n");        
    }
}
int menu(){
    int ch;
    printf("\n1. Insert value to the list");
    printf("\n2. Delete value from the list");
    printf("\n3. View list");
    printf("\n4. Exit\n");
    scanf("%d",&ch);
    return ch;
    }
int main(){ 
    while(1){
        switch(menu()){
            case 1:
            insertNode();
            break;
            case 2:
            deleteNode();
            break;
            case 3:
            viewList();
            break;
            case 4:
            exit(0);
            default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}








