#ifndef NODE_H
#define NODE_H

#include <iostream> // Inclui funcionalidades b�sicas de entrada/sa�da

// Estrutura de um n� para a lista encadeada, pilha e fila
struct Node {
    int data; // Dado armazenado no n� (inteiro, conforme solicitado)
    Node* next; // Ponteiro para o pr�ximo n� na sequ�ncia

    // Construtor do n�: inicializa o dado com 'val' e o ponteiro 'next' como nulo
    Node(int val) : data(val), next(nullptr) {}
};

#endif // NODE_H
