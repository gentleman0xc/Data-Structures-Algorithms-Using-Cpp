// Stack with Linked List 
#include <iostream>
using namespace std; 

class Node{ 
    public: 
        int data; 
        Node *next; 
}; 

class Stack { 
    public: 
        Node *top; 
        Stack(){ 
            top = NULL; 
        }
        void push(int data); 
        void pop(); 
        int peek(); 
        void display(); 
};

// Inserir um elemento / Operação Push 
void Stack::push(int n){ 
    Node *newNode = new Node(); 
    newNode->data = n; 
    if (top == NULL) { // verificamos se o nó no topo e´nulo ou nao
        newNode->next = NULL; // se for = pilha vazia, atribuimos next com valor NULO
    }
    else { 
        newNode->next = top; // variavel de referencia de newNode se torna o valor do topo anterior
    }
    top = newNode; // top vira  a referencia do newNode
}

// Deletar um elemento / Operação Pop: 
void Stack::pop() { 
    Node* temp; 
    if (top == NULL) { // verifica se a pilha está vazia 
        cout << "Stack Underflow" << endl; 
        return; 
    }
    // se a variavel superior não for nula deleta o elemento do topo
    temp = top; // variavel temporaria contendo o nó excluido 
    top = top->next;  // a referencia do nó se torna o top 
    delete temp; // apaga a var temporaria
}

// MNostrar o topo da pilha / Operação Peek: 
int Stack::peek(){ 
    // Verifique se está vazia 
    if (top == NULL ){ 
        cout << "\nStack Underflow";
        return -1;
    }
    return top->data; 
}

// Mostrar todos os elementos da pilha 
void Stack::display(){ 
    Node *temp; 
    // Verifica se a pilha está vazia 
    if (top == NULL) { 
        cout << "\nStack Underflow"; 
    }
    else { 
        temp = top; 
        while (temp != NULL) { 
            cout << temp->data << " "; 
            temp = temp->next; 
        }
    }
}

int main() { 
    Stack stk; 
    stk.push(30);
    stk.push(20);
    stk.push(50);
    stk.push(70);
    stk.display(); 
    stk.pop(); 
    int top_value = stk.peek(); 
    if (top_value != -1) { 
        cout << "\nO valor do topo eh: " << top_value << "\n"; 
    }
    cout << "Elementos depois da operação POP: \n"; 
    stk.display();

    return 0; 
}