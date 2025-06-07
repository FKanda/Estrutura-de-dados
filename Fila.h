#ifndef FILA_H
#define FILA_H

#include "Node.h" // Inclui a defini��o da estrutura Node
#include <string> // Para uso de std::string (embora n�o diretamente em Fila.h)

// --- Fun��es da biblioteca de Fila ---

// Adiciona um elemento (dado) ao final da fila (enqueue)
void enqueue(Node*& front, Node*& rear, int data);

// Remove e retorna o elemento do in�cio da fila (dequeue)
int dequeue(Node*& front, Node*& rear);

// Retorna o elemento do in�cio da fila sem remov�-lo (peekFila)
int peekFila(Node* front);

// Verifica se a fila est� vazia (isEmptyFila)
bool isEmptyFila(Node* front);

// Libera toda a mem�ria alocada para os n�s da fila (deleteFila)
void deleteFila(Node*& front, Node*& rear);

// a. Imprimir uma fila
// Imprime todos os elementos da fila sem modific�-la.
void imprimirFila(Node* front, Node* rear);

// b. Buscar e editar um elemento da fila
// Busca o 'valorAntigo' e o substitui por 'valorNovo' (primeira ocorr�ncia).
void buscarEditarElementoFila(Node*& front, Node*& rear, int valorAntigo, int valorNovo);

// c. Buscar e remover um elemento da fila
// Busca o 'valor' e o remove (primeira ocorr�ncia).
void buscarRemoverElementoFila(Node*& front, Node*& rear, int valor);

// d. Remover todas as repeti��es da fila
// Remove todas as ocorr�ncias repetidas, mantendo a primeira de cada valor.
void removerRepeticoesFila(Node*& front, Node*& rear);

// e. Remover todos os pares da fila
// Remove todos os n�meros pares da fila.
void removerParesFila(Node*& front, Node*& rear);

#endif // FILA_H
