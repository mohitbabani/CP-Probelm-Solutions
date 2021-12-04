// // // #include<stdio.h>
// // // #include<conio.h>
// // // int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;
// // // void bfs(int v) {
// // // 	for (i=1;i<=n;i++)
// // // 	  if(a[v][i] && !visited[i])
// // // 	   q[++r]=i;
// // // 	if(f<=r) {
// // // 		visited[q[f]]=1;
// // // 		bfs(q[f++]);
// // // 	}
// // // }
// // // void main() {
// // // 	int v;
// // // 	printf("\n Enter the number of vertices:");
// // // 	scanf("%d",&n);
// // // 	for (i=1;i<=n;i++) {
// // // 		q[i]=0;
// // // 		visited[i]=0;
// // // 	}
// // // 	printf("\n Enter graph data in matrix form:\n");
// // // 	for (i=1;i<=n;i++)
// // // 	  for (j=1;j<=n;j++)
// // // 	   scanf("%d",&a[i][j]);
// // // 	printf("\n Enter the starting vertex:");
// // // 	scanf("%d",&v);
// // // 	bfs(v);
// // // 	printf("\n The node which are reachable are:\n");
// // // 	for (i=1;i<=n;i++)
// // // 	  if(visited[i])
// // // 	   printf("%d\t",i); else
// // // 	   printf("\n Bfs is not possible");
// // // 	getch();
// // // }
// // #include<stdio.h>
// // #include<conio.h>
// // int a[20][20],reach[20],n;
// // void dfs(int v) {
// // 	int i;
// // 	reach[v]=1;
// // 	for (i=1;i<=n;i++)
// // 	  if(a[v][i] && !reach[i]) {
// // 		printf("\n %d->%d",v,i);
// // 		dfs(i);
// // 	}
// // }
// // void main() {
// // 	int i,j,count=0;

// // 	printf("\n Enter number of vertices:");
// // 	scanf("%d",&n);
// // 	for (i=1;i<=n;i++) {
// // 		reach[i]=0;
// // 		for (j=1;j<=n;j++)
// // 		   a[i][j]=0;
// // 	}
// // 	printf("\n Enter the adjacency matrix:\n");
// // 	for (i=1;i<=n;i++)
// // 	  for (j=1;j<=n;j++)
// // 	   scanf("%d",&a[i][j]);
// // 	dfs(1);
// // 	printf("\n");
// // 	for (i=1;i<=n;i++) {
// // 		if(reach[i])
// // 		   count++;
// // 	}
// // 	if(count==n)
// // 	    printf("\n Graph is connected"); 
// //     else
// // 	    printf("\n Graph is not connected");


// // }
// /*
//  * C Program to Implement a Queue using an Array
//  */
// #include <stdio.h>
 
// #define MAX 50
 
// void insert();
// void delete();
// void display();
// int queue_array[MAX];
// int rear = - 1;
// int front = - 1;
// int main()
// {
//     insert();
//     insert();
//     insert();
//     insert();
//     insert();
//     delete();
//     delete();
//     display();
// } /* End of main() */
 
// void insert()
// {
//     int add_item;
//     if (rear == MAX - 1)
//     printf("Queue Overflow \n");
//     else
//     {
//         if (front == - 1)
//         /*If queue is initially empty */
//         front = 0;
//         printf("Inset the element in queue : ");
//         scanf("%d", &add_item);
//         rear = rear + 1;
//         queue_array[rear] = add_item;
//     }
// } /* End of insert() */
 
// void delete()
// {
//     if (front == - 1 || front > rear)
//     {
//         printf("Queue Underflow \n");
//         return ;
//     }
//     else
//     {
//         printf("Element deleted from queue is : %d\n", queue_array[front]);
//         front = front + 1;
//     }
// } /* End of delete() */
 
// void display()
// {
//     int i;
//     if (front == - 1)
//         printf("Queue is empty \n");
//     else
//     {
//         printf("Queue is : \n");
//         for (i = front; i <= rear; i++)
//             printf("%d ", queue_array[i]);
//         printf("\n");
//     }
// } /* End of display() */
// A C++ program for Dijkstra's single source shortest path algorithm. 
// The program is for adjacency matrix representation of the graph 
  
#include <limits.h> 
#include <stdio.h> 
  
// Number of vertices in the graph 
#define V 9 
  
// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(int dist[], int sptSet[]) 
{ 
    // Initialize min value 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == 0 && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
  
// A utility function to print the constructed distance array 
int printSolution(int dist[], int n) 
{ 
    printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < V; i++) 
        printf("%d tt %d\n", i, dist[i]); 
} 
  
// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void dijkstra(int graph[V][V], int src) 
{ 
    int dist[V]; // The output array.  dist[i] will hold the shortest 
    // distance from src to i 
  
    int sptSet[V]; // sptSet[i] will be 1 if vertex i is included in shortest 
    // path tree or shortest distance from src to i is finalized 
  
    // Initialize all distances as INFINITE and stpSet[] as 0 
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = 0; 
  
    // Distance of source vertex from itself is always 0 
    dist[src] = 0; 
  
    // Find shortest path for all vertices 
    for (int count = 0; count < V - 1; count++) { 
        // Pick the minimum distance vertex from the set of vertices not 
        // yet processed. u is always equal to src in the first iteration. 
        int u = minDistance(dist, sptSet); 
  
        // Mark the picked vertex as processed 
        sptSet[u] = 1; 
  
        // Update dist value of the adjacent vertices of the picked vertex. 
        for (int v = 0; v < V; v++) 
  
            // Update dist[v] only if is not in sptSet, there is an edge from 
            // u to v, and total weight of path from src to  v through u is 
            // smaller than current value of dist[v] 
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 
  
    // print the constructed distance array 
    printSolution(dist, V); 
} 
  
// driver program to test above function 
int main() 
{ 
    /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    dijkstra(graph, 0); 
  
    return 0; 
} 