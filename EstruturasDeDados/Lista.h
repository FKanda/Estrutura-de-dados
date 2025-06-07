#ifndef LISTA_H
#define LISTA_H

#include "Node.h"   // Inclui a defini��o da estrutura Node
#include <string>   // Necess�rio para o tipo std::string usado na fun��o printList

// --- Fun��es da biblioteca de Lista ---

// 1. Percorrer lista (Percurso):

// 1.1 Fun��o que retorna o menor elemento da lista
int minLista(Node* lista);

// 1.2 Fun��o que retorna o maior elemento da lista
int maxLista(Node* lista);

// 1.3 Fun��o que retorna a m�dia dos elementos da lista
double mediaLista(Node* lista); // Usado 'double' para maior precis�o na m�dia

// 1.4 Fun��o que retorna o n�mero de elementos da lista
int lenLista(Node* lista);

// --- Fun��es auxiliares para manipula��o da lista (j� existentes e �teis) ---

// Insere um novo elemento no final da lista
void insertEnd(Node*& head, int data);

// Imprime todos os elementos da lista, com um nome opcional para a lista
void printList(Node* lista, const std::string& name = "Lista");

// Libera toda a mem�ria alocada para os n�s da lista
void deleteList(Node*& head);

// 2. Fun��o que concatena duas listas L1 e L2:
// Concatena L2 no final de L1 e retorna L1 como a nova cabe�a da lista resultante.
Node* appendLista(Node* L1, Node* L2);

// 3. Fun��o que inverte uma lista:
// Inverte toda a ordem dos elementos na lista.
Node* reverseLista(Node* lista);

// 4. Fun��o que verifica se L2 � uma sublista de L1:
// Retorna '1' (verdadeiro) se L2 for uma sublista de L1, ou '0' (falso) caso contr�rio.
int isSubLista(Node* L1, Node* L2);

#endif // LISTA_H
