
#include <iostream>
#include <vector>

class Node {
public:
    int vertex;  // Armazena o vértice do nó
    int weight;  // Armazena o peso da aresta
    Node* next;  // Ponteiro para o próximo nó na lista de adjacência

    Node(int v, int w) : vertex(v), weight(w), next(nullptr) {}
    // Construtor que inicializa o vértice e peso do nó e define o próximo como nullptr
};

void create(std::vector<Node*>& head) {
    char ch = 'y';
    int v1, v2, choice, no, weight;
    Node* newNode;
    Node* temp;

    std::cout << "0 - Directed Graph\n";
    std::cout << "1 - Undirected Graph\n";
    std::cout << "Enter your choice (0 or 1): ";
    std::cin >> choice;

    std::cout << "Enter the number of edges: ";
    std::cin >> no;

    for (int i = 0; i < no; i++) {
        std::cout << "\nEnter the starting node, ending node, and weight: ";
        std::cin >> v1 >> v2 >> weight;

        // Cria um novo nó com o vértice e peso fornecidos
        newNode = new Node(v2, weight);
        temp = head[v1];

        if (temp == nullptr) {
            // Se o nó atual for nulo, atribui o novo nó como o primeiro nó na lista de adjacência
            head[v1] = newNode;
        }
        else {
            // Caso contrário, percorre a lista de adjacência até o último nó e adiciona o novo nó
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        if (choice == 1) {
            // Se a escolha for um grafo não direcionado, realiza as mesmas etapas para o outro vértice
            newNode = new Node(v1, weight);
            temp = head[v2];

            if (temp == nullptr) {
                head[v2] = newNode;
            }
            else {
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
    }
}

void display(const std::vector<Node*>& head, int n) {
    std::cout << "Adjacency List:\n";
    for (int v = 0; v < n; v++) {
        std::cout << "Head[" << v << "]";
        Node* adj = head[v];
        while (adj != nullptr) {
            // Percorre a lista de adjacência e exibe os vértices adjacentes e os pesos das arestas
            std::cout << adj->vertex << "=>weight:" << adj->weight << " ";
            adj = adj->next;
        }
        std::cout << "\n";
    }
}

int main() {
    int n;
    std::cout << "Number of vertices in the graph: ";
    std::cin >> n;

    // Cria um vetor de ponteiros para nós e inicializa todos como nullptr
    std::vector<Node*> head(n, nullptr);

    create(head);
    display(head, n);

    // Libera a memória alocada pelos nós
    for (int i = 0; i < n; i++) {
        Node* curr = head[i];
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    return 0;
}

