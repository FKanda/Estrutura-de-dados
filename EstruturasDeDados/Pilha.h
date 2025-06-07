#ifndef PILHA_H
#define PILHA_H

#include "Node.h" // Inclui a definição da estrutura Node
#include <string> // Para uso de std::string (embora não diretamente em Pilha.h, é boa prática para futuras expansões)

// --- Funções da biblioteca de Pilha ---

// Adiciona um elemento (dado) ao topo da pilha
void push(Node*& top, int data);

// Remove e retorna o elemento do topo da pilha
int pop(Node*& top);

// Retorna o elemento do topo da pilha sem removê-lo
int peek(Node* top);

// Verifica se a pilha está vazia
bool isEmpty(Node* top);

// Imprime todos os elementos da pilha (do topo para a base)
void printPilha(Node* top);

// Libera toda a memória alocada para os nós da pilha
void deletePilha(Node*& top);

// a. Crie uma função que busque um elemento de uma pilha.
// Retorna 1 se o elemento for encontrado, 0 caso contrário.
int buscarElementoPilha(Node* top, int valor);

// b. Cria uma função que busque e remova um elemento de uma pilha.
// Remove a primeira ocorrência do valor encontrado, se houver.
void buscarRemoverElementoPilha(Node*& top, int valor);

// c. Crie uma função que remova todos os números pares de uma pilha.
void removerParesPilha(Node*& top);

// d. Crie uma função que remova todos os valores repetidos de uma pilha.
// Mantém apenas a primeira ocorrência de cada valor, removendo as repetições.
void removerRepetidosPilha(Node*& top);

#endif // PILHA_H
