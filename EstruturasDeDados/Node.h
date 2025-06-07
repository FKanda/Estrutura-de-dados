#ifndef NODE_H
#define NODE_H

#include <iostream> // Inclui funcionalidades básicas de entrada/saída

// Estrutura de um nó para a lista encadeada, pilha e fila
struct Node {
    int data; // Dado armazenado no nó (inteiro, conforme solicitado)
    Node* next; // Ponteiro para o próximo nó na sequência

    // Construtor do nó: inicializa o dado com 'val' e o ponteiro 'next' como nulo
    Node(int val) : data(val), next(nullptr) {}
};

#endif // NODE_H
