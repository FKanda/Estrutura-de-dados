#include "Fila.h"     // Inclui o cabe�alho da Fila
#include <iostream>   // Para entrada/sa�da (std::cout, std::cerr)
#include <set>        // Para usar std::set na fun��o de remover repetidos

// Implementa��o: Adiciona um elemento ao final da fila (enqueue)
void enqueue(Node*& front, Node*& rear, int data) {
    Node* newNode = new Node(data); // Cria um novo n�
    if (isEmptyFila(front)) { // Se a fila estiver vazia, o novo n� � o primeiro e o �ltimo
        front = newNode;
        rear = newNode;
    } else { // Se n�o estiver vazia, o novo n� � adicionado ap�s o 'rear'
        rear->next = newNode;
        rear = newNode; // O novo n� se torna o novo 'rear'
    }
}

// Implementa��o: Remove e retorna o elemento do in�cio da fila (dequeue)
int dequeue(Node*& front, Node*& rear) {
    if (isEmptyFila(front)) { // Verifica se a fila est� vazia
        std::cerr << "Erro: Fila vazia. Nao e possivel remover elemento." << std::endl;
        return -1; // Retorna um valor de erro
    }
    Node* temp = front;    // Salva o n� do in�cio temporariamente
    int data = temp->data; // Pega o dado do n�
    front = front->next;   // O novo 'front' � o pr�ximo n�
    if (front == nullptr) { // Se a fila ficou vazia ap�s a remo��o
        rear = nullptr;     // 'rear' tamb�m deve ser nulo
    }
    delete temp;           // Libera a mem�ria do n� removido
    return data;           // Retorna o dado removido
}

// Implementa��o: Retorna o elemento do in�cio sem remover (peekFila)
int peekFila(Node* front) {
    if (isEmptyFila(front)) { // Verifica se a fila est� vazia
        std::cerr << "Erro: Fila vazia. Nao ha elemento para 'peek'." << std::endl;
        return -1; // Retorna um valor de erro
    }
    return front->data; // Retorna o dado do in�cio da fila
}

// Implementa��o: Verifica se a fila est� vazia
bool isEmptyFila(Node* front) {
    return front == nullptr; // Retorna true se 'front' � nulo, false caso contr�rio
}

// Implementa��o: Libera a mem�ria alocada para a fila
void deleteFila(Node*& front, Node*& rear) {
    Node* current = front;    // Come�a do in�cio
    Node* nextNode;           // Vari�vel tempor�ria
    while (current != nullptr) { // Percorre a fila
        nextNode = current->next; // Salva o pr�ximo n�
        delete current;           // Deleta o n� atual
        current = nextNode;       // Move para o pr�ximo n�
    }
    front = nullptr; // Define 'front' como nulo
    rear = nullptr;  // Define 'rear' como nulo
}

// a. Imprimir uma fila
// Nota: Esta fun��o cria uma c�pia tempor�ria da fila para imprimir sem modificar a original.
void imprimirFila(Node* front, Node* rear) {
    std::cout << "Fila: ["; // In�cio da representa��o da fila
    if (isEmptyFila(front)) { // Se a fila estiver vazia, imprime apenas os colchetes
        std::cout << "]" << std::endl;
        return;
    }

    Node* tempFront = nullptr; // Cabe�a da fila tempor�ria
    Node* tempRear = nullptr;  // Cauda da fila tempor�ria

    Node* current = front; // Come�a a percorrer a fila original
    while (current != nullptr) { // Enfileira todos os elementos na fila tempor�ria
        enqueue(tempFront, tempRear, current->data);
        current = current->next;
    }

    // Agora, desenfileira e imprime da fila tempor�ria
    while (!isEmptyFila(tempFront)) {
        int data = dequeue(tempFront, tempRear); // Pega o elemento
        std::cout << data;                     // Imprime o elemento
        if (!isEmptyFila(tempFront)) {        // Se ainda houver elementos, adiciona v�rgula e espa�o
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl; // Fim da representa��o da fila
}

// b. Buscar e editar um elemento da fila
// Busca o 'valorAntigo' e o substitui por 'valorNovo' (primeira ocorr�ncia).
void buscarEditarElementoFila(Node*& front, Node*& rear, int valorAntigo, int valorNovo) {
    if (isEmptyFila(front)) { // Se a fila estiver vazia
        std::cout << "Fila vazia. Nao e possivel buscar e editar." << std::endl;
        return;
    }

    Node* tempFront = nullptr; // Fila tempor�ria
    Node* tempRear = nullptr;
    bool found = false;        // Flag para indicar se o elemento foi encontrado e editado

    while (!isEmptyFila(front)) { // Percorre a fila original
        int currentData = dequeue(front, rear); // Pega o elemento
        if (currentData == valorAntigo && !found) { // Se encontrou o valor antigo e ainda n�o editou
            enqueue(tempFront, tempRear, valorNovo); // Enfileira o novo valor
            found = true;                            // Marca como encontrado e editado
            std::cout << "Elemento " << valorAntigo << " editado para " << valorNovo << std::endl;
        } else {
            enqueue(tempFront, tempRear, currentData); // Mant�m o elemento original
        }
    }

    // Transfere todos os elementos de volta para a fila original
    front = tempFront;
    rear = tempRear;

    if (!found) { // Se o elemento antigo n�o foi encontrado
        std::cout << "Elemento " << valorAntigo << " nao encontrado para edicao." << std::endl;
    }
}

// c. Buscar e remover um elemento da fila
// Busca o 'valor' e o remove (primeira ocorr�ncia).
void buscarRemoverElementoFila(Node*& front, Node*& rear, int valor) {
    if (isEmptyFila(front)) { // Se a fila estiver vazia
        std::cout << "Fila vazia. Nao e possivel buscar e remover." << std::endl;
        return;
    }

    Node* tempFront = nullptr; // Fila tempor�ria
    Node* tempRear = nullptr;
    bool found = false;        // Flag para indicar se o elemento foi encontrado e removido

    while (!isEmptyFila(front)) { // Percorre a fila original
        int currentData = dequeue(front, rear); // Pega o elemento
        if (currentData == valor && !found) { // Se encontrou o valor e ainda n�o o removeu
            found = true;                      // Marca como encontrado e removido
            std::cout << "Elemento " << valor << " encontrado e removido." << std::endl;
            // N�o enfileira 'currentData' na fila tempor�ria, efetivamente removendo-o
        } else {
            enqueue(tempFront, tempRear, currentData); // Enfileira o elemento na fila tempor�ria
        }
    }

    // Transfere todos os elementos de volta para a fila original
    front = tempFront;
    rear = tempRear;

    if (!found) { // Se o elemento n�o foi encontrado
        std::cout << "Elemento " << valor << " nao encontrado para remocao." << std::endl;
    }
}

// d. Remover todas as repeti��es da fila
// Remove todas as ocorr�ncias repetidas, mantendo a primeira de cada valor.
void removerRepeticoesFila(Node*& front, Node*& rear) {
    if (isEmptyFila(front)) { // Se a fila estiver vazia
        std::cout << "Fila vazia. Nao ha repeticoes para remover." << std::endl;
        return;
    }

    Node* tempFront = nullptr;   // Fila tempor�ria para elementos �nicos
    Node* tempRear = nullptr;
    std::set<int> seenElements;  // 'set' para rastrear elementos j� vistos

    while (!isEmptyFila(front)) { // Percorre a fila original
        int currentData = dequeue(front, rear); // Pega o elemento
        // Se o elemento n�o foi visto antes
        if (seenElements.find(currentData) == seenElements.end()) {
            enqueue(tempFront, tempRear, currentData); // Enfileira o elemento �nico
            seenElements.insert(currentData);         // Marca como visto
        } else {
            std::cout << "Removendo repetido: " << currentData << std::endl;
        }
    }

    // Transfere os elementos �nicos de volta para a fila original
    front = tempFront;
    rear = tempRear;
}

// e. Remover todos os pares da fila
void removerParesFila(Node*& front, Node*& rear) {
    if (isEmptyFila(front)) { // Se a fila estiver vazia
        std::cout << "Fila vazia. Nao ha pares para remover." << std::endl;
        return;
    }

    Node* tempFront = nullptr; // Fila tempor�ria para elementos �mpares
    Node* tempRear = nullptr;

    while (!isEmptyFila(front)) { // Percorre a fila original
        int currentData = dequeue(front, rear); // Pega o elemento
        if (currentData % 2 != 0) { // Se o elemento for �mpar
            enqueue(tempFront, tempRear, currentData); // Enfileira na fila tempor�ria
        } else {
            std::cout << "Removendo par: " << currentData << std::endl;
        }
    }

    // Transfere os elementos �mpares de volta para a fila original
    front = tempFront;
    rear = tempRear;
}
