#include<bits/stdc++.h>
struct ArrayStack{
    int top;
    int capacity;
    int *array;
};
struct ArrayStack* createStack(int cap){
    struct ArrayStack *stack;
    stack=(struct ArrayStack *)malloc(sizeof(struct ArrayStack));
    stack->capacity=cap;
    stack->top=-1;
    stack->array=(int *)malloc(sizeof(int)*stack->capacity);
    return stack;    
}
int isFull(struct ArrayStack *stack){
    if(stack->top == stack->capacity-1)
    return 1;
    else 
    return 0;
}
int isEmpty(struct ArrayStack *stack){
    if(stack->top==-1)
    return 1;
    else 
    return 0;
}
void push(struct ArrayStack *stack,int item){
    if(!isFull(stack)){
    stack->top++;
    stack->array[stack->top]=item;
    printf("\nPushed value is %d\n",item);
    }
    else
    printf("\nStack is full\n");
}
int pop(struct ArrayStack *stack){
    int item;
    if(!isEmpty(stack)){
        item = stack->array[stack->top];
        stack->top--;
        return item;
    }
    else
    return -1;
}
int main(){
    int item,choice;
    struct ArrayStack *stack;
    stack=createStack(5);
    while(1){
        printf("\nEnter your choice\n1. Push\n2. Pop\n3. Exit\n\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("\nEnter the value you wish to push\n\n");
            scanf("%d",&item);
            push(stack,item);
            break;
        case 2:
            item = pop(stack);
            if(item==-1)
            printf("\nStack is empty\n");
            else
            printf("\nPopped value is %d\n",item);
            break;
        case 3:
            exit (0);
        default:
            printf("\nInvalid choice\n");
        }
    }
}