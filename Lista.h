#ifndef LISTA_H
#define LISTA_H

#include "Node.h"   // Inclui a definição da estrutura Node
#include <string>   // Necessário para o tipo std::string usado na função printList

// --- Funções da biblioteca de Lista ---

// 1. Percorrer lista (Percurso):

// 1.1 Função que retorna o menor elemento da lista
int minLista(Node* lista);

// 1.2 Função que retorna o maior elemento da lista
int maxLista(Node* lista);

// 1.3 Função que retorna a média dos elementos da lista
double mediaLista(Node* lista); // Usado 'double' para maior precisão na média

// 1.4 Função que retorna o número de elementos da lista
int lenLista(Node* lista);

// --- Funções auxiliares para manipulação da lista (já existentes e úteis) ---

// Insere um novo elemento no final da lista
void insertEnd(Node*& head, int data);

// Imprime todos os elementos da lista, com um nome opcional para a lista
void printList(Node* lista, const std::string& name = "Lista");

// Libera toda a memória alocada para os nós da lista
void deleteList(Node*& head);

// 2. Função que concatena duas listas L1 e L2:
// Concatena L2 no final de L1 e retorna L1 como a nova cabeça da lista resultante.
Node* appendLista(Node* L1, Node* L2);

// 3. Função que inverte uma lista:
// Inverte toda a ordem dos elementos na lista.
Node* reverseLista(Node* lista);

// 4. Função que verifica se L2 é uma sublista de L1:
// Retorna '1' (verdadeiro) se L2 for uma sublista de L1, ou '0' (falso) caso contrário.
int isSubLista(Node* L1, Node* L2);

#endif // LISTA_H
