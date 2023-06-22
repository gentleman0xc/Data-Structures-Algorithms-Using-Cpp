// Inserindo um nó no inicio 
// [data][refer] --> [data][refer] --> [data][refer]

#include <iostream>
using namespace std; 

class Node {
    public: 
        int data; // dados 
        Node* next;  // referencia para o proximo nó 
};

class LinkedList {
    public: 
        Node *head, *tail; //head = primeiro elemento, tail = ultimo elemento, ambos do tipo node
        LinkedList() { // construtor 
            head = NULL; // iniciando os head como nulo 
            tail = NULL; // iniciando a tail como nulo 
        }
    
void insertNodeAtFront(int value) {

    // alocar memória para o novo nó e armazenar dados nele
    Node *newNode = new Node;  // cria um novo objeto nó 
    newNode->data = value;  // armazena o valor como seu parametro para o atributo de dados 
    newNode->next = NULL; // armazena NULL para o proximo atribudo 

    if(head == NULL) { // verifica se head é nulo ou nao 
        head = newNode; 
        tail = newNode; 
    }
    else { 
        newNode->next = head;
        head=newNode; 
    }

}
// O código abaixo recebe um valor inteiro como entrada  e insere um novo nó com esse valor no final de uma lista encadeada.  
void insertNodeAtEnd(int value){
    // cria um novo nó com o valor fornecido
    Node *newNode = new Node; 
    newNode->data = value; // "->" é usado para acessar os membros de uma classe por meio de um ponteiro. 
    newNode->next = NULL; // define o proximo ponteiro do novo nó como NULL

    /*
     No codigo acima, a variavel newNode é um ponteiro para um objeto Node.  
     As expressoes newNode->data e newNode->next acessam os membros de  data e next do objeto Node apontado por newNode. 
    
    */

    if(head == NULL){ // se a lista estiver vazia, o novo nó se tornará o head e o tail.
        head = new Node; 
        tail = head; 
        return; 
    }

    else { // ele define o próximo ponteiro do nó final para o novo nó e, em seguida, define o nó final para o novo nó.
        tail->next = newNode; 
        tail = tail->next; 
        return;
    }
}

void insertAtPosition(int pos, int value) { // a função recebe dois parametros: posição do novo nó e o valor do novo nó
    // Criamos 3 novos objetos Node: 'prev', 'current' e 'NewNode'
    // prev e current será usado para percorrer a lista
    Node *prev = new Node; 
    Node *current = new Node; 
    current=head; 
    // newNode será o novo nó que está sendo inserido. 
    Node *newNode = new Node; 
    newNode->data = value; 
    newNode->next = NULL; 

    if(pos < 1) { // pos menor que 1 = imprime mensagem de erro
        cout << "Position cannot be less than one."; 
    } else if(pos == 1) { 
        newNode->next = head; // define o proximo ponteiro do novo nó para o inicio da lista vinculada
        head = newNode; // define o inicio da lista vinculada 
    }
    else { 
        for(int i = 0; i < pos; i++){ 
            prev = current; 
            current = current->next; 
            if(current == NULL) { 
                cout << "Invalid position"; 
            }
        }
        prev->next = newNode; 
        newNode->next = current; 
    }
}
/*
Diagrama do que acontece na função anterior 

pos = 3
value = 5

----------------------------------
Initial linked list:

head -> 1 -> 2 -> 3 -> NULL

After calling insertAtPosition(3, 5):

head -> 1 -> 2 -> 5 -> 3 -> NULL

*/
// A função abaixo recebe um valor inteiro como entrada e procura esse valor na lista encadeada. 
void search(int value){ 
    Node *current = head; // current aponta para o nó principal (head) da lista.
    while(current!=NULL){ // iniciamos um loop que continuará enquanto o nó atual não for nulo
        if(current->data == value) { // verifica se os dados armazenados no nó atual são iguais ao valor que foi passado como entrada.
            cout << "Element " << value << " is found" << endl; // imprime a mensagem que o elemento foi encontrado
            return; 
        }
        current = current->next; // move o nó atual para o proximo nó na lista encadeada 
    }

    cout << "Element " << value << " not found in this list." << endl; 

}

// Uma função que não requer entrada e imprime o conteúdo de uma lista encadeada no console.
void displayList() { 
    Node *current = head; // variavel current que aponta para o nó principal da lista encadeada.
    while(current != NULL) { // loop que continuará enquanto o nó atual não for nulo.
        cout << current->data << " "; // imprime os dados armazenados no nó atual para o console
        current = current->next; // Move o nó atual para o proximo nó na lista encadeada. 
    }
    cout << endl; 
}

// função que usa um valor inteiro como entrada e exclui o primeiro nó na lista encadeada que contém esse valor.
void deleteNode(int value) { 
    bool flag = false; 
    Node *current = new Node; // cria um novo nó
    Node *previous = new Node; // cria um novo nó 
    previous = head; // apontar para o nó principal
    current = head; // apontar para o nó principal 
    while(current != NULL) { // executa enquanto o nó atual não for NULO
        if(current->data == value && current == head){ // verifica se o nó atual é igual ao valor passado e se o nó atual é o nó principal
            // exclui o nó e define o flag para verdadeiro
            head = current->next; 
            free(current); 
            flag = true; 
            break; 
            }
        else if(current->data == value){ // verofoca se os dados armazenados no nó atual é igual ao valor que foi passado.
            // exclui o nó e define flag para verdadeiro
            previous->next = current->next; 
            if(current == tail) { 
                tail = previous; 
            }
            free(current); 
            flag = true; 
            break; 
        }
        else { // dados atual não é igual ao valor que foi passado. 
            // move o nó atual para o proximo nó na lista encadeada 
            previous = current; 
            current = current -> next; 
        }
    }

    if(flag == true){
        cout << "Elemento deletado!" << endl; 
    }
    else { 
        cout << "elemento não encontrado!" << endl; 
    }
}


}; // class Linkedlist termina aqui



 int main() { 
    LinkedList lst; 
    lst.insertNodeAtFront(10); 
    lst.insertNodeAtEnd(40); 
    lst.insertNodeAtEnd(50); 
    lst.insertAtPosition(2, 20); 
    lst.insertAtPosition(3, 30); 
    lst.displayList();
    lst.search(30); 
    lst.deleteNode(30); 
    lst.displayList();

    return 0;

 }