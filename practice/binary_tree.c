#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
    int data;
    struct node *l,*r;
};
int count=0;
struct node* create(){
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data (-1 for no node)\n");
    scanf("%d",&x);
    count++;
    if( x == -1 ){
        count--;
        return 0;
    }
    newnode->data = x;

    printf("Enter left child of %d\n",x);
    newnode->l = create();
    printf("Enter right child of %d\n",x);
    newnode->r = create();

    return newnode;
}

void preorder(struct node *root){
    if(root == 0) return;

    printf("%d ",root->data);
    preorder(root->l);
    preorder(root->r);
}

void inorder(struct node *root){
    if(root == 0) return;

    inorder(root->l);
    printf("%d ",root->data);
    inorder(root->r);
}

void postorder(struct node *root){
    if(root == 0) return;

    postorder(root->l);
    postorder(root->r);
    printf("%d ",root->data);
}
int max(int a,int b){
    return a > b ? a : b;
}
int height(struct node *root){
    if(root == 0) 
        return 0;
    return 1 + max(height(root->l),height(root->r));
}

int main(){
    struct node *root;
    root = create();
    printf("%d %d",height(root),count);
    // printf("\nPreorder  : ");
    // preorder(root);
    // printf("\nInorder   : ");
    // inorder(root);
    // printf("\nPostorder : ");
    // postorder(root);
}