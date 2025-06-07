#include "Fila.h"     // Inclui o cabeçalho da Fila
#include <iostream>   // Para entrada/saída (std::cout, std::cerr)
#include <set>        // Para usar std::set na função de remover repetidos

// Implementação: Adiciona um elemento ao final da fila (enqueue)
void enqueue(Node*& front, Node*& rear, int data) {
    Node* newNode = new Node(data); // Cria um novo nó
    if (isEmptyFila(front)) { // Se a fila estiver vazia, o novo nó é o primeiro e o último
        front = newNode;
        rear = newNode;
    } else { // Se não estiver vazia, o novo nó é adicionado após o 'rear'
        rear->next = newNode;
        rear = newNode; // O novo nó se torna o novo 'rear'
    }
}

// Implementação: Remove e retorna o elemento do início da fila (dequeue)
int dequeue(Node*& front, Node*& rear) {
    if (isEmptyFila(front)) { // Verifica se a fila está vazia
        std::cerr << "Erro: Fila vazia. Nao e possivel remover elemento." << std::endl;
        return -1; // Retorna um valor de erro
    }
    Node* temp = front;    // Salva o nó do início temporariamente
    int data = temp->data; // Pega o dado do nó
    front = front->next;   // O novo 'front' é o próximo nó
    if (front == nullptr) { // Se a fila ficou vazia após a remoção
        rear = nullptr;     // 'rear' também deve ser nulo
    }
    delete temp;           // Libera a memória do nó removido
    return data;           // Retorna o dado removido
}

// Implementação: Retorna o elemento do início sem remover (peekFila)
int peekFila(Node* front) {
    if (isEmptyFila(front)) { // Verifica se a fila está vazia
        std::cerr << "Erro: Fila vazia. Nao ha elemento para 'peek'." << std::endl;
        return -1; // Retorna um valor de erro
    }
    return front->data; // Retorna o dado do início da fila
}

// Implementação: Verifica se a fila está vazia
bool isEmptyFila(Node* front) {
    return front == nullptr; // Retorna true se 'front' é nulo, false caso contrário
}

// Implementação: Libera a memória alocada para a fila
void deleteFila(Node*& front, Node*& rear) {
    Node* current = front;    // Começa do início
    Node* nextNode;           // Variável temporária
    while (current != nullptr) { // Percorre a fila
        nextNode = current->next; // Salva o próximo nó
        delete current;           // Deleta o nó atual
        current = nextNode;       // Move para o próximo nó
    }
    front = nullptr; // Define 'front' como nulo
    rear = nullptr;  // Define 'rear' como nulo
}

// a. Imprimir uma fila
// Nota: Esta função cria uma cópia temporária da fila para imprimir sem modificar a original.
void imprimirFila(Node* front, Node* rear) {
    std::cout << "Fila: ["; // Início da representação da fila
    if (isEmptyFila(front)) { // Se a fila estiver vazia, imprime apenas os colchetes
        std::cout << "]" << std::endl;
        return;
    }

    Node* tempFront = nullptr; // Cabeça da fila temporária
    Node* tempRear = nullptr;  // Cauda da fila temporária

    Node* current = front; // Começa a percorrer a fila original
    while (current != nullptr) { // Enfileira todos os elementos na fila temporária
        enqueue(tempFront, tempRear, current->data);
        current = current->next;
    }

    // Agora, desenfileira e imprime da fila temporária
    while (!isEmptyFila(tempFront)) {
        int data = dequeue(tempFront, tempRear); // Pega o elemento
        std::cout << data;                     // Imprime o elemento
        if (!isEmptyFila(tempFront)) {        // Se ainda houver elementos, adiciona vírgula e espaço
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl; // Fim da representação da fila
}

// b. Buscar e editar um elemento da fila
// Busca o 'valorAntigo' e o substitui por 'valorNovo' (primeira ocorrência).
void buscarEditarElementoFila(Node*& front, Node*& rear, int valorAntigo, int valorNovo) {
    if (isEmptyFila(front)) { // Se a fila estiver vazia
        std::cout << "Fila vazia. Nao e possivel buscar e editar." << std::endl;
        return;
    }

    Node* tempFront = nullptr; // Fila temporária
    Node* tempRear = nullptr;
    bool found = false;        // Flag para indicar se o elemento foi encontrado e editado

    while (!isEmptyFila(front)) { // Percorre a fila original
        int currentData = dequeue(front, rear); // Pega o elemento
        if (currentData == valorAntigo && !found) { // Se encontrou o valor antigo e ainda não editou
            enqueue(tempFront, tempRear, valorNovo); // Enfileira o novo valor
            found = true;                            // Marca como encontrado e editado
            std::cout << "Elemento " << valorAntigo << " editado para " << valorNovo << std::endl;
        } else {
            enqueue(tempFront, tempRear, currentData); // Mantém o elemento original
        }
    }

    // Transfere todos os elementos de volta para a fila original
    front = tempFront;
    rear = tempRear;

    if (!found) { // Se o elemento antigo não foi encontrado
        std::cout << "Elemento " << valorAntigo << " nao encontrado para edicao." << std::endl;
    }
}

// c. Buscar e remover um elemento da fila
// Busca o 'valor' e o remove (primeira ocorrência).
void buscarRemoverElementoFila(Node*& front, Node*& rear, int valor) {
    if (isEmptyFila(front)) { // Se a fila estiver vazia
        std::cout << "Fila vazia. Nao e possivel buscar e remover." << std::endl;
        return;
    }

    Node* tempFront = nullptr; // Fila temporária
    Node* tempRear = nullptr;
    bool found = false;        // Flag para indicar se o elemento foi encontrado e removido

    while (!isEmptyFila(front)) { // Percorre a fila original
        int currentData = dequeue(front, rear); // Pega o elemento
        if (currentData == valor && !found) { // Se encontrou o valor e ainda não o removeu
            found = true;                      // Marca como encontrado e removido
            std::cout << "Elemento " << valor << " encontrado e removido." << std::endl;
            // Não enfileira 'currentData' na fila temporária, efetivamente removendo-o
        } else {
            enqueue(tempFront, tempRear, currentData); // Enfileira o elemento na fila temporária
        }
    }

    // Transfere todos os elementos de volta para a fila original
    front = tempFront;
    rear = tempRear;

    if (!found) { // Se o elemento não foi encontrado
        std::cout << "Elemento " << valor << " nao encontrado para remocao." << std::endl;
    }
}

// d. Remover todas as repetições da fila
// Remove todas as ocorrências repetidas, mantendo a primeira de cada valor.
void removerRepeticoesFila(Node*& front, Node*& rear) {
    if (isEmptyFila(front)) { // Se a fila estiver vazia
        std::cout << "Fila vazia. Nao ha repeticoes para remover." << std::endl;
        return;
    }

    Node* tempFront = nullptr;   // Fila temporária para elementos únicos
    Node* tempRear = nullptr;
    std::set<int> seenElements;  // 'set' para rastrear elementos já vistos

    while (!isEmptyFila(front)) { // Percorre a fila original
        int currentData = dequeue(front, rear); // Pega o elemento
        // Se o elemento não foi visto antes
        if (seenElements.find(currentData) == seenElements.end()) {
            enqueue(tempFront, tempRear, currentData); // Enfileira o elemento único
            seenElements.insert(currentData);         // Marca como visto
        } else {
            std::cout << "Removendo repetido: " << currentData << std::endl;
        }
    }

    // Transfere os elementos únicos de volta para a fila original
    front = tempFront;
    rear = tempRear;
}

// e. Remover todos os pares da fila
void removerParesFila(Node*& front, Node*& rear) {
    if (isEmptyFila(front)) { // Se a fila estiver vazia
        std::cout << "Fila vazia. Nao ha pares para remover." << std::endl;
        return;
    }

    Node* tempFront = nullptr; // Fila temporária para elementos ímpares
    Node* tempRear = nullptr;

    while (!isEmptyFila(front)) { // Percorre a fila original
        int currentData = dequeue(front, rear); // Pega o elemento
        if (currentData % 2 != 0) { // Se o elemento for ímpar
            enqueue(tempFront, tempRear, currentData); // Enfileira na fila temporária
        } else {
            std::cout << "Removendo par: " << currentData << std::endl;
        }
    }

    // Transfere os elementos ímpares de volta para a fila original
    front = tempFront;
    rear = tempRear;
}
