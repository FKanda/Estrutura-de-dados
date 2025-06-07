#include "Pilha.h"    // Inclui o cabeçalho da Pilha
#include <iostream>   // Para entrada/saída (std::cout, std::cerr)
#include <set>        // Para usar std::set na função de remover repetidos (eficiente para verificar unicidade)

// Implementação: Adiciona um elemento ao topo da pilha (push)
void push(Node*& top, int data) {
    Node* newNode = new Node(data); // Cria um novo nó
    newNode->next = top;            // O novo nó aponta para o que era o topo
    top = newNode;                  // O novo nó se torna o topo
}

// Implementação: Remove e retorna o elemento do topo da pilha (pop)
int pop(Node*& top) {
    if (isEmpty(top)) { // Verifica se a pilha está vazia
        std::cerr << "Erro: Pilha vazia. Nao e possivel remover elemento." << std::endl;
        return -1; // Retorna um valor de erro
    }
    Node* temp = top;    // Salva o nó do topo temporariamente
    int data = temp->data; // Pega o dado do topo
    top = top->next;     // O novo topo é o próximo nó
    delete temp;         // Libera a memória do nó removido
    return data;         // Retorna o dado removido
}

// Implementação: Retorna o elemento do topo sem remover (peek)
int peek(Node* top) {
    if (isEmpty(top)) { // Verifica se a pilha está vazia
        std::cerr << "Erro: Pilha vazia. Nao ha elemento para 'peek'." << std::endl;
        return -1; // Retorna um valor de erro
    }
    return top->data; // Retorna o dado do topo
}

// Implementação: Verifica se a pilha está vazia
bool isEmpty(Node* top) {
    return top == nullptr; // Retorna true se o topo é nulo (pilha vazia), false caso contrário
}

// Implementação: Imprime os elementos da pilha (do topo para a base)
void printPilha(Node* top) {
    std::cout << "Pilha: ["; // Início da representação da pilha
    Node* current = top;     // Começa do topo
    while (current != nullptr) { // Percorre a pilha
        std::cout << current->data; // Imprime o dado
        if (current->next != nullptr) { // Adiciona vírgula e espaço se não for o último
            std::cout << ", ";
        }
        current = current->next; // Move para o próximo nó
    }
    std::cout << "]" << std::endl; // Fim da representação da pilha
}

// Implementação: Libera a memória alocada para a pilha
void deletePilha(Node*& top) {
    Node* current = top;     // Começa do topo
    Node* nextNode;          // Variável temporária
    while (current != nullptr) { // Percorre a pilha
        nextNode = current->next; // Salva o próximo nó
        delete current;           // Deleta o nó atual
        current = nextNode;       // Move para o próximo nó
    }
    top = nullptr; // Define o topo como nulo após a exclusão
}

// a. Crie uma função que busque um elemento de uma pilha.
// Nota: Esta função é não-destrutiva para a pilha original.
int buscarElementoPilha(Node* top, int valor) {
    Node* current = top; // Começa do topo
    while (current != nullptr) { // Percorre a pilha
        if (current->data == valor) { // Se o valor for encontrado
            return 1; // Retorna 1 (verdadeiro)
        }
        current = current->next; // Move para o próximo nó
    }
    return 0; // Retorna 0 (falso) se o valor não for encontrado
}

// b. Cria uma função que busque e remova um elemento de uma pilha.
// (Assume-se que remove a primeira ocorrência encontrada do topo para a base)
void buscarRemoverElementoPilha(Node*& top, int valor) {
    if (isEmpty(top)) { // Se a pilha estiver vazia
        std::cout << "Pilha vazia. Nao e possivel buscar e remover." << std::endl;
        return;
    }

    Node* tempPilha = nullptr; // Cria uma pilha temporária
    bool found = false;        // Flag para indicar se o elemento foi encontrado

    // Remove elementos da pilha original e os move para a pilha temporária
    // até encontrar o valor a ser removido ou a pilha original ficar vazia.
    while (!isEmpty(top)) {
        int currentData = pop(top); // Pega o elemento do topo da pilha original
        if (currentData == valor && !found) { // Se encontrou o valor e ainda não o removeu
            found = true; // Marca como encontrado
            std::cout << "Elemento " << valor << " encontrado e removido." << std::endl;
        } else {
            push(tempPilha, currentData); // Empurra para a pilha temporária
        }
    }

    // Move os elementos de volta da pilha temporária para a pilha original
    // Isso restaura a ordem original dos elementos não removidos.
    while (!isEmpty(tempPilha)) {
        push(top, pop(tempPilha)); // Move de volta para a pilha original
    }

    if (!found) { // Se o elemento não foi encontrado
        std::cout << "Elemento " << valor << " nao encontrado na pilha." << std::endl;
    }
}

// c. Crie uma função que remova todos os números pares de uma pilha.
void removerParesPilha(Node*& top) {
    if (isEmpty(top)) { // Se a pilha estiver vazia
        std::cout << "Pilha vazia. Nao ha pares para remover." << std::endl;
        return;
    }

    Node* tempPilha = nullptr; // Pilha temporária para guardar os elementos ímpares

    while (!isEmpty(top)) { // Percorre a pilha original
        int currentData = pop(top); // Pega o elemento do topo
        if (currentData % 2 != 0) { // Se o elemento for ímpar
            push(tempPilha, currentData); // Empurra para a pilha temporária
        } else {
            std::cout << "Removendo par: " << currentData << std::endl;
        }
    }

    // Move os elementos de volta da pilha temporária para a pilha original
    while (!isEmpty(tempPilha)) {
        push(top, pop(tempPilha)); // Restaura a pilha com os ímpares
    }
}

// d. Crie uma função que remova todos os valores repetidos de uma pilha.
// Mantém a primeira ocorrência de cada elemento (do topo para a base).
void removerRepetidosPilha(Node*& top) {
    if (isEmpty(top)) { // Se a pilha estiver vazia
        std::cout << "Pilha vazia. Nao ha repeticoes para remover." << std::endl;
        return;
    }

    Node* tempPilha = nullptr;   // Pilha temporária para armazenar elementos únicos
    std::set<int> seenElements;  // Um 'set' para rastrear elementos já vistos (garante unicidade)

    while (!isEmpty(top)) { // Percorre a pilha original
        int currentData = pop(top); // Pega o elemento do topo
        // Se o elemento não foi visto antes
        if (seenElements.find(currentData) == seenElements.end()) {
            push(tempPilha, currentData);       // Adiciona à pilha temporária
            seenElements.insert(currentData);   // Marca como visto
        } else {
            std::cout << "Removendo repetido: " << currentData << std::endl;
        }
    }

    // Move os elementos de volta da pilha temporária para a pilha original
    // Isso restaura a ordem relativa dos elementos únicos.
    while (!isEmpty(tempPilha)) {
        push(top, pop(tempPilha)); // Restaura a pilha com os elementos únicos
    }
}
