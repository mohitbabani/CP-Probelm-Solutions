#include<bits/stdc++.h>

struct node{
    int info;
    struct node *prev,*next;
};
struct node *start=NULL;
void insertAsFirst(){
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    printf("Enter the no:\n");
    scanf("%d",&n->info);
    n->next=NULL;
    n->prev=NULL;
    if(start==NULL)
    start=n;
    else{
        start->prev=n;
        n->next=start;
        start=n;
    }
}
void deleteFirstNode(){
    struct node *r;
    if(start==NULL)
    printf("List empty");
    else{
        r=start;
         start=start->next;
         start->prev=NULL;
         free(r);
    }
}
void viewList(){
    struct node *t;
    if(start==NULL)
    printf("List is empty");
    else{
        t=start;
        while(t->next!=NULL){
            printf("%d ",t->info);
            t=t->next;
        }
    }
}
int menu(){
    printf("\n1. Insert Node\n2. Delete node\n3. View List\n4. Exit\n");
    int n;
    scanf("%d",&n);
    return n;
}
int main(){
    while(1){
        switch(menu()){
            case 1:
            insertAsFirst();
            break;
            case 2:
            deleteFirstNode();
            break;
            case 3:
            viewList();
            break;
            case 4:
            exit(0);
            default:
            printf("\nInvalid operation");
        }
    }
}