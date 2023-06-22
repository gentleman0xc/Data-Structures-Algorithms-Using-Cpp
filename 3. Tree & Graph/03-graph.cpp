#include <iostream> 
using namespace std; 

// grafo não direcionado 
void addEdge(int aMatrix[][4], int row, int col){ 
    aMatrix[row][col] = 1; 
    aMatrix[col][row] = 1; 
}

void display(int aMatrix[][4]) { 
    for (int row = 0; row < 4; row++){ 
        for (int col = 0; col < 4; col++) { 
            cout << aMatrix[row][col] << " "; 
        }
        cout << "\n"; 
    }
}

int main() { 
    int numVertices;

    int adjMatrix[4][4]={0}; 
    addEdge(adjMatrix, 0, 1); //adiciona uma aresta entre o vértice 0 e o vértice 1.
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 1, 2); 
    addEdge(adjMatrix, 2, 0);
    addEdge(adjMatrix, 2, 3);

    display(adjMatrix); 
}