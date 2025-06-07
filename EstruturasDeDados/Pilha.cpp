#include "Pilha.h"    // Inclui o cabe�alho da Pilha
#include <iostream>   // Para entrada/sa�da (std::cout, std::cerr)
#include <set>        // Para usar std::set na fun��o de remover repetidos (eficiente para verificar unicidade)

// Implementa��o: Adiciona um elemento ao topo da pilha (push)
void push(Node*& top, int data) {
    Node* newNode = new Node(data); // Cria um novo n�
    newNode->next = top;            // O novo n� aponta para o que era o topo
    top = newNode;                  // O novo n� se torna o topo
}

// Implementa��o: Remove e retorna o elemento do topo da pilha (pop)
int pop(Node*& top) {
    if (isEmpty(top)) { // Verifica se a pilha est� vazia
        std::cerr << "Erro: Pilha vazia. Nao e possivel remover elemento." << std::endl;
        return -1; // Retorna um valor de erro
    }
    Node* temp = top;    // Salva o n� do topo temporariamente
    int data = temp->data; // Pega o dado do topo
    top = top->next;     // O novo topo � o pr�ximo n�
    delete temp;         // Libera a mem�ria do n� removido
    return data;         // Retorna o dado removido
}

// Implementa��o: Retorna o elemento do topo sem remover (peek)
int peek(Node* top) {
    if (isEmpty(top)) { // Verifica se a pilha est� vazia
        std::cerr << "Erro: Pilha vazia. Nao ha elemento para 'peek'." << std::endl;
        return -1; // Retorna um valor de erro
    }
    return top->data; // Retorna o dado do topo
}

// Implementa��o: Verifica se a pilha est� vazia
bool isEmpty(Node* top) {
    return top == nullptr; // Retorna true se o topo � nulo (pilha vazia), false caso contr�rio
}

// Implementa��o: Imprime os elementos da pilha (do topo para a base)
void printPilha(Node* top) {
    std::cout << "Pilha: ["; // In�cio da representa��o da pilha
    Node* current = top;     // Come�a do topo
    while (current != nullptr) { // Percorre a pilha
        std::cout << current->data; // Imprime o dado
        if (current->next != nullptr) { // Adiciona v�rgula e espa�o se n�o for o �ltimo
            std::cout << ", ";
        }
        current = current->next; // Move para o pr�ximo n�
    }
    std::cout << "]" << std::endl; // Fim da representa��o da pilha
}

// Implementa��o: Libera a mem�ria alocada para a pilha
void deletePilha(Node*& top) {
    Node* current = top;     // Come�a do topo
    Node* nextNode;          // Vari�vel tempor�ria
    while (current != nullptr) { // Percorre a pilha
        nextNode = current->next; // Salva o pr�ximo n�
        delete current;           // Deleta o n� atual
        current = nextNode;       // Move para o pr�ximo n�
    }
    top = nullptr; // Define o topo como nulo ap�s a exclus�o
}

// a. Crie uma fun��o que busque um elemento de uma pilha.
// Nota: Esta fun��o � n�o-destrutiva para a pilha original.
int buscarElementoPilha(Node* top, int valor) {
    Node* current = top; // Come�a do topo
    while (current != nullptr) { // Percorre a pilha
        if (current->data == valor) { // Se o valor for encontrado
            return 1; // Retorna 1 (verdadeiro)
        }
        current = current->next; // Move para o pr�ximo n�
    }
    return 0; // Retorna 0 (falso) se o valor n�o for encontrado
}

// b. Cria uma fun��o que busque e remova um elemento de uma pilha.
// (Assume-se que remove a primeira ocorr�ncia encontrada do topo para a base)
void buscarRemoverElementoPilha(Node*& top, int valor) {
    if (isEmpty(top)) { // Se a pilha estiver vazia
        std::cout << "Pilha vazia. Nao e possivel buscar e remover." << std::endl;
        return;
    }

    Node* tempPilha = nullptr; // Cria uma pilha tempor�ria
    bool found = false;        // Flag para indicar se o elemento foi encontrado

    // Remove elementos da pilha original e os move para a pilha tempor�ria
    // at� encontrar o valor a ser removido ou a pilha original ficar vazia.
    while (!isEmpty(top)) {
        int currentData = pop(top); // Pega o elemento do topo da pilha original
        if (currentData == valor && !found) { // Se encontrou o valor e ainda n�o o removeu
            found = true; // Marca como encontrado
            std::cout << "Elemento " << valor << " encontrado e removido." << std::endl;
        } else {
            push(tempPilha, currentData); // Empurra para a pilha tempor�ria
        }
    }

    // Move os elementos de volta da pilha tempor�ria para a pilha original
    // Isso restaura a ordem original dos elementos n�o removidos.
    while (!isEmpty(tempPilha)) {
        push(top, pop(tempPilha)); // Move de volta para a pilha original
    }

    if (!found) { // Se o elemento n�o foi encontrado
        std::cout << "Elemento " << valor << " nao encontrado na pilha." << std::endl;
    }
}

// c. Crie uma fun��o que remova todos os n�meros pares de uma pilha.
void removerParesPilha(Node*& top) {
    if (isEmpty(top)) { // Se a pilha estiver vazia
        std::cout << "Pilha vazia. Nao ha pares para remover." << std::endl;
        return;
    }

    Node* tempPilha = nullptr; // Pilha tempor�ria para guardar os elementos �mpares

    while (!isEmpty(top)) { // Percorre a pilha original
        int currentData = pop(top); // Pega o elemento do topo
        if (currentData % 2 != 0) { // Se o elemento for �mpar
            push(tempPilha, currentData); // Empurra para a pilha tempor�ria
        } else {
            std::cout << "Removendo par: " << currentData << std::endl;
        }
    }

    // Move os elementos de volta da pilha tempor�ria para a pilha original
    while (!isEmpty(tempPilha)) {
        push(top, pop(tempPilha)); // Restaura a pilha com os �mpares
    }
}

// d. Crie uma fun��o que remova todos os valores repetidos de uma pilha.
// Mant�m a primeira ocorr�ncia de cada elemento (do topo para a base).
void removerRepetidosPilha(Node*& top) {
    if (isEmpty(top)) { // Se a pilha estiver vazia
        std::cout << "Pilha vazia. Nao ha repeticoes para remover." << std::endl;
        return;
    }

    Node* tempPilha = nullptr;   // Pilha tempor�ria para armazenar elementos �nicos
    std::set<int> seenElements;  // Um 'set' para rastrear elementos j� vistos (garante unicidade)

    while (!isEmpty(top)) { // Percorre a pilha original
        int currentData = pop(top); // Pega o elemento do topo
        // Se o elemento n�o foi visto antes
        if (seenElements.find(currentData) == seenElements.end()) {
            push(tempPilha, currentData);       // Adiciona � pilha tempor�ria
            seenElements.insert(currentData);   // Marca como visto
        } else {
            std::cout << "Removendo repetido: " << currentData << std::endl;
        }
    }

    // Move os elementos de volta da pilha tempor�ria para a pilha original
    // Isso restaura a ordem relativa dos elementos �nicos.
    while (!isEmpty(tempPilha)) {
        push(top, pop(tempPilha)); // Restaura a pilha com os elementos �nicos
    }
}
