#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

// Queue implementation using array
int queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;


void enqueue(int data) {
    if (rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue overflow!\n");
        exit(1); 
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = data;
}



int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow!\n");
        exit(1);
    }
    int data = queue[front];
    front++;
    return data;
}

// BFS implementation
void bfs(int graph[][100], int num_nodes, int start_node) {
    int visited[num_nodes]; // array to keep track of visited nodes
    for (int i = 0; i < num_nodes; i++) {
        visited[i] = 0;
    }
    visited[start_node] = 1;
    enqueue(start_node);
    while (front != -1) {
        int curr_node = dequeue();
        printf("%d ", curr_node);
        for (int i = 0; i < num_nodes; i++) {
            if (graph[curr_node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(i);
            }
        } 
    }
}

// Driver program to test the BFS implementation
int main() {
    int num_nodes, start_node;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &num_nodes);
    int graph[num_nodes][100];
    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the starting node for BFS traversal: ");
    scanf("%d", &start_node);
    printf("BFS traversal of the graph starting from node %d: ", start_node);
    bfs(graph, num_nodes, start_node);
    printf("\n");
    return 0;
}
