#include <stdio.h>
#include <stdlib.h>
#define Max 10  // Define max nodes

// -------- Stack Initialization -----------
int top = -1;
char stk[Max];

int isEmpty() { return top == -1; }
void push(char item) { stk[++top] = item; }
char pop() { return stk[top--]; }

// Visited array initialization
int visited[Max] = {0};             

void DFS(int vertices, int adj[Max][Max], char start) {
    push(start);
    visited[start - 'A'] = 1;  // Mark starting node as visited
    
    printf("DFS Traversal: ");
    while (!isEmpty()) {
        char u = pop();
        printf("%c ", u);

        int nodeIndex = u - 'A';  // Convert character to index

        for (int i = 0; i < vertices; i++) {
            if (adj[nodeIndex][i] == 1 && !visited[i]) {  // Check adjacency + unvisited
                push(i + 'A');
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    FILE *file = fopen("graph.txt", "r");
    if (file == NULL) {
        printf("File can't be opened\n");
        return 1;
    }

    int vertex;
    fscanf(file, "%d", &vertex);  // Read number of vertices
    printf("The number of vertices in the graph is %d\n", vertex);
    
    int adj[Max][Max];  // Adjacency matrix storage
    
    printf("The adjacency matrix of the graph is:\n");
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            fscanf(file, "%d", &adj[i][j]);
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    fclose(file);  // Close the file

    printf("\nEnter the starting vertex (A, B, C...): ");
    char start;
    scanf(" %c", &start);  // Read character input

    DFS(vertex, adj, start);

    return 0;
}
