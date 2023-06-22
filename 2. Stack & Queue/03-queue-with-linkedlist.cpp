#include <iostream>
using namespace std; 

class Node { 
    public: 
        int data; 
        Node *next; 
};

// Criação da classe queue 
class Queue{ 
    public: 
        Node *front, *rear; // variavel de referencia front e rear 
        Queue(){ 
            front=rear=NULL; // definimos front e rear como nulo com o construtor
        }

        void enQueue(int n); 
        void deQueue(); 
        void display(); 
};

// Operação de Inserir (EnQueue)
void Queue::enQueue(int n){ 
    Node *newNode = new Node(); 
    newNode->data = n; 
    newNode->next = NULL; 
    if(front == NULL) { 
        front=rear=newNode; 
    }
    else { 
        rear->next = newNode; 
        rear = newNode; 
    }

    cout << n << " Elemento Inserted" << endl;
}

// Operação de Remover item 
void Queue::deQueue(){ 
    if (front == NULL) { 
        cout << " Queue Underflow" << endl; ; 
    }

    Node *tempPtr = front; 
    if (front == rear){ 
        front=rear=NULL; 
    } else { 
        front = front->next; 
        cout << "\n" << tempPtr->data << "Element deleted" << endl; 
    }
    delete tempPtr;
}

void Queue::display(){ 
    if (front == NULL) { 
        cout << "Queue Underflow" << endl; 
    }
    Node *temp = front; 
    while(temp != NULL){ 
        cout << temp->data << " "; 
        temp = temp->next; 
    }
}

int main(){ 
    Queue q; 
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    cout << "Lista atual" << endl; 
    q.display(); 
    q.deQueue(); 
    q.deQueue(); 
    cout << "Lista após as operacoes de deQueue: " << endl; 
    q.display(); 


    return 0; 
}