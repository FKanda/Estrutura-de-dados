#ifndef FILA_H
#define FILA_H

#include "Node.h" // Inclui a definição da estrutura Node
#include <string> // Para uso de std::string (embora não diretamente em Fila.h)

// --- Funções da biblioteca de Fila ---

// Adiciona um elemento (dado) ao final da fila (enqueue)
void enqueue(Node*& front, Node*& rear, int data);

// Remove e retorna o elemento do início da fila (dequeue)
int dequeue(Node*& front, Node*& rear);

// Retorna o elemento do início da fila sem removê-lo (peekFila)
int peekFila(Node* front);

// Verifica se a fila está vazia (isEmptyFila)
bool isEmptyFila(Node* front);

// Libera toda a memória alocada para os nós da fila (deleteFila)
void deleteFila(Node*& front, Node*& rear);

// a. Imprimir uma fila
// Imprime todos os elementos da fila sem modificá-la.
void imprimirFila(Node* front, Node* rear);

// b. Buscar e editar um elemento da fila
// Busca o 'valorAntigo' e o substitui por 'valorNovo' (primeira ocorrência).
void buscarEditarElementoFila(Node*& front, Node*& rear, int valorAntigo, int valorNovo);

// c. Buscar e remover um elemento da fila
// Busca o 'valor' e o remove (primeira ocorrência).
void buscarRemoverElementoFila(Node*& front, Node*& rear, int valor);

// d. Remover todas as repetições da fila
// Remove todas as ocorrências repetidas, mantendo a primeira de cada valor.
void removerRepeticoesFila(Node*& front, Node*& rear);

// e. Remover todos os pares da fila
// Remove todos os números pares da fila.
void removerParesFila(Node*& front, Node*& rear);

#endif // FILA_H
