#ifndef PILHA_H
#define PILHA_H

#include "Node.h" // Inclui a defini��o da estrutura Node
#include <string> // Para uso de std::string (embora n�o diretamente em Pilha.h, � boa pr�tica para futuras expans�es)

// --- Fun��es da biblioteca de Pilha ---

// Adiciona um elemento (dado) ao topo da pilha
void push(Node*& top, int data);

// Remove e retorna o elemento do topo da pilha
int pop(Node*& top);

// Retorna o elemento do topo da pilha sem remov�-lo
int peek(Node* top);

// Verifica se a pilha est� vazia
bool isEmpty(Node* top);

// Imprime todos os elementos da pilha (do topo para a base)
void printPilha(Node* top);

// Libera toda a mem�ria alocada para os n�s da pilha
void deletePilha(Node*& top);

// a. Crie uma fun��o que busque um elemento de uma pilha.
// Retorna 1 se o elemento for encontrado, 0 caso contr�rio.
int buscarElementoPilha(Node* top, int valor);

// b. Cria uma fun��o que busque e remova um elemento de uma pilha.
// Remove a primeira ocorr�ncia do valor encontrado, se houver.
void buscarRemoverElementoPilha(Node*& top, int valor);

// c. Crie uma fun��o que remova todos os n�meros pares de uma pilha.
void removerParesPilha(Node*& top);

// d. Crie uma fun��o que remova todos os valores repetidos de uma pilha.
// Mant�m apenas a primeira ocorr�ncia de cada valor, removendo as repeti��es.
void removerRepetidosPilha(Node*& top);

#endif // PILHA_H
