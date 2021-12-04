#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <string.h>
#define RANGE 255
#define print(x) printf("%d ",x)
#define M 50
int binary_search(int a[],int l,int r,int v){
	if(l<=r){
		int mid = (l+r)/2;
		if(a[mid] == v) return mid;
		if(a[mid] > v) return binary_search(a,l,mid-1,v);
		if(a[mid] < v) return binary_search(a,mid+1,r,v);
	}
	return -1;
}
void inputArray(int a[],int n){
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
}
void printArray(int a[],int n){
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
				// STACK using Array
// int stack[M];
// int top = -1;
// int isFull(){
// 	return top == M-1;
// }
// int isEmpty(){
// 	return top == -1;
// }
// void push(int a){
// 	if(!isFull()){
// 		top++;
// 		stack[top] = a;
// 	}
// }
// void pop(){
// 	if(!isEmpty()){
// 		stack[top] = -1;
// 		top--;
// 	}
// }
// int peek(){
// 	if(!isEmpty())
// 	return stack[top];
// }
// void displayStack(){
// 	int i;
// 	for(i=top;i>=0;i--)
// 		printf("%d ",stack[i]);
// 	printf("\n");
// }
					// STACK using LL
// struct node{
// 	int data;
// 	struct node* link;
// };
// struct node *top = NULL;
// int isEmpty(){
// 	return top == NULL;
// }
// void insert(int x){
// 	struct node *newnode = (struct node *)malloc(sizeof(struct node));
// 	newnode->data = x;
// 	newnode->link = top;
// 	top = newnode;
// }
// void delete(){
// 	if(!isEmpty()){
// 		struct node* temp = top->link;
// 		top = temp;
// 	}
// }
// void display(){
// 	struct node* temp = top;
// 	while(!isEmpty()){
// 		printf("%d\n",temp->data);
// 		temp = temp->link;
// 	}
// }
// 			// Tower Of Hanoi
// 			// S = source, I = Intermediate, T = Target
// void TOH(int n,char S,char I,char T){
// 	if(n == 1){ 
// 		printf("%c -> %c\n",S,T);
// 		return;
// 	}
// 	TOH(n-1,S,T,I);
// 	TOH(1,S,I,T);
// 	TOH(n-1,I,S,T);
// }
void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}	
void bubbleSort(int a[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;i++)
			if(a[i] > a[i+1]) swap(&a[i],&a[j]);
	}
}
void insertionSort(int a[],int n){
	int i,key,j;
	for(i=1;i<n;i++){
		key = a[i];
		j = i-1;
		while(j >= 0 && a[j] > key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key; 
	}
}
void selectionSort(int a[],int n){
	int i,j,mid_ind;
	for(i=0;i<n;i++){
		int mid = i;
		for(j=i+1;j<n;j++){
			if(a[j] < a[mid])
			mid = j;
		}
		swap(&a[i],&a[mid]);
	}
}
void countingSort(char arr[]){
	char ans[strlen(arr)];
	int i;
	int count[RANGE+1]={0};
	for(i=0;arr[i];i++){
		count[arr[i]]++;
	}

}
void merge(int a[],int l,int m,int r){
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1],R[n2];
	int i,j,k;
	
	for(i=0;i<n1;i++) L[i] = a[i+l];
	for(j=0;j<n2;j++) R[j] = a[j+m+1];

	i=j=0;
	k = l;
	while(i<n1 && j<n2){
		if(L[i] < R[j]){
			a[k] = L[i]; 
			i++;
		}
		else{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		a[k] = L[i];
		i++;
		k++;
	}
	while(j<n2){
		a[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort2(int a[],int l,int r){
	if(l < r){
		int m = l + (r-l)/2;

		mergeSort2(a,l,m);
		mergeSort2(a,m+1,r);

		merge(a,l,m,r);
	}
}
void mergeSort(int a[],int n){
	mergeSort2(a,0,n-1);
}
struct node
{
	int data;
	struct node *l,*r;
	/* data */
};
struct node* create(){
	int x;
	struct node* newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter Data(-1 for no node)\n");
	scanf("%d",&x);
	
	if(x==-1) return 0;
	newnode->data = x;
	printf("Enter the left node\n");
	newnode->l = create();
	printf("Enter the right node\n");
	newnode->r = create();

	return newnode;
}
int main(){
	int a[] = {2,5,4,1,5};
	mergeSort(a,5);
	printArray(a,5);
}
