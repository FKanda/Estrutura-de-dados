#include <iostream> // Para entrada/sa�da (cout, endl)
#include <string>   // Para usar std::string (nomes das listas)

// Inclui todos os cabe�alhos das bibliotecas que criamos
#include "Node.h"
#include "Lista.h"
#include "Pilha.h"
#include "Fila.h"

int main() {
    std::cout << "--- Validacao das Funcoes da Lista ---" << std::endl;
    Node* minhaLista = nullptr; // Inicializa a cabe�a da lista como nula

    // Adiciona alguns elementos � lista
    insertEnd(minhaLista, 10);
    insertEnd(minhaLista, 4);
    insertEnd(minhaLista, 20);
    insertEnd(minhaLista, 5);
    insertEnd(minhaLista, 15);
    printList(minhaLista, "Minha Lista Original"); // Imprime o estado inicial da lista

    // Testa as fun��es de percurso
    std::cout << "Menor elemento: " << minLista(minhaLista) << std::endl;
    std::cout << "Maior elemento: " << maxLista(minhaLista) << std::endl;
    std::cout << "Media dos elementos: " << mediaLista(minhaLista) << std::endl;
    std::cout << "Numero de elementos: " << lenLista(minhaLista) << std::endl;

    // Teste da fun��o appendLista (concatenar listas)
    Node* L1 = nullptr; // Cria a primeira lista
    insertEnd(L1, 1);
    insertEnd(L1, 2);
    Node* L2 = nullptr; // Cria a segunda lista
    insertEnd(L2, 3);
    insertEnd(L2, 4);
    printList(L1, "L1 Original");
    printList(L2, "L2 Original");
    Node* L_concatenada = appendLista(L1, L2); // Concatena L2 no final de L1
    printList(L_concatenada, "L1 Apos Concatenacao (L1 agora contem L2)"); // Imprime a lista concatenada
    // Nota: 'L2' agora faz parte de 'L1'. N�o delete 'L2' separadamente.

    // Teste da fun��o reverseLista (inverter lista)
    Node* listaParaInverter = nullptr; // Cria uma nova lista para inverter
    insertEnd(listaParaInverter, 10);
    insertEnd(listaParaInverter, 20);
    insertEnd(listaParaInverter, 30);
    printList(listaParaInverter, "Lista para Inverter");
    listaParaInverter = reverseLista(listaParaInverter); // Inverte a lista
    printList(listaParaInverter, "Lista Invertida");     // Imprime a lista invertida

    // Teste da fun��o isSubLista (verificar sublista)
    Node* L_principal = nullptr; // Cria a lista principal
    insertEnd(L_principal, 1);
    insertEnd(L_principal, 2);
    insertEnd(L_principal, 3);
    insertEnd(L_principal, 4);
    insertEnd(L_principal, 5);
    printList(L_principal, "Lista Principal (L_principal)");

    Node* L_sub1 = nullptr; // Exemplo de sublista verdadeira
    insertEnd(L_sub1, 2);
    insertEnd(L_sub1, 3);
    printList(L_sub1, "Sublista 1 (L_sub1)");

    Node* L_sub2 = nullptr; // Exemplo de sublista falsa
    insertEnd(L_sub2, 3);
    insertEnd(L_sub2, 5); // N�o � sublista porque o 5 n�o segue o 3 diretamente
    printList(L_sub2, "Sublista 2 (L_sub2)");

    Node* L_sub_vazia = nullptr; // Exemplo de sublista vazia
    printList(L_sub_vazia, "Sublista Vazia");

    std::cout << "L_sub1 e sublista de L_principal? " << (isSubLista(L_principal, L_sub1) ? "Sim" : "Nao") << std::endl;
    std::cout << "L_sub2 e sublista de L_principal? " << (isSubLista(L_principal, L_sub2) ? "Sim" : "Nao") << std::endl;
    std::cout << "Sublista vazia e sublista de L_principal? " << (isSubLista(L_principal, L_sub_vazia) ? "Sim" : "Nao") << std::endl;
    std::cout << "Sublista vazia e sublista de lista vazia? " << (isSubLista(nullptr, L_sub_vazia) ? "Sim" : "Nao") << std::endl;
    std::cout << "L_principal e sublista de lista vazia? " << (isSubLista(nullptr, L_principal) ? "Sim" : "Nao") << std::endl;

    // Libera a mem�ria alocada para as listas ap�s todos os testes
    deleteList(minhaLista);
    deleteList(L_concatenada); // L_concatenada � L1 ap�s a concatena��o, ent�o deleta ambas
    deleteList(listaParaInverter);
    deleteList(L_principal);
    deleteList(L_sub1);
    deleteList(L_sub2);
    // L_sub_vazia j� � nullptr, n�o precisa deletar

    std::cout << "\n--- Validacao das Funcoes da Pilha ---" << std::endl;
    Node* minhaPilha = nullptr; // Inicializa o topo da pilha como nulo

    // Adiciona elementos � pilha
    push(minhaPilha, 10);
    push(minhaPilha, 20);
    push(minhaPilha, 5);
    push(minhaPilha, 20); // Valor repetido
    push(minhaPilha, 30);
    push(minhaPilha, 4); // Valor par
    printPilha(minhaPilha); // Imprime o estado inicial da pilha

    // Testa a fun��o buscarElementoPilha
    std::cout << "Elemento 5 esta na pilha? " << (buscarElementoPilha(minhaPilha, 5) ? "Sim" : "Nao") << std::endl;
    std::cout << "Elemento 100 esta na pilha? " << (buscarElementoPilha(minhaPilha, 100) ? "Sim" : "Nao") << std::endl;

    // Testa a fun��o buscarRemoverElementoPilha
    buscarRemoverElementoPilha(minhaPilha, 20); // Tenta remover a primeira ocorr�ncia de 20
    printPilha(minhaPilha);

    buscarRemoverElementoPilha(minhaPilha, 99); // Tenta remover um elemento que n�o existe
    printPilha(minhaPilha);

    // Testa a fun��o removerParesPilha
    removerParesPilha(minhaPilha);
    printPilha(minhaPilha);

    // Testa a fun��o removerRepetidosPilha
    removerRepetidosPilha(minhaPilha); // Remove valores repetidos restantes
    printPilha(minhaPilha);

    deletePilha(minhaPilha); // Libera a mem�ria da pilha
    printPilha(minhaPilha); // Imprime a pilha vazia
    std::cout << "Pilha esta vazia? " << (isEmpty(minhaPilha) ? "Sim" : "Nao") << std::endl;

    std::cout << "\n--- Validacao das Funcoes da Fila ---" << std::endl;
    Node* minhaFilaFront = nullptr; // In�cio da fila
    Node* minhaFilaRear = nullptr;  // Fim da fila

    // Adiciona elementos � fila
    enqueue(minhaFilaFront, minhaFilaRear, 1);
    enqueue(minhaFilaFront, minhaFilaRear, 2);
    enqueue(minhaFilaFront, minhaFilaRear, 3);
    enqueue(minhaFilaFront, minhaFilaRear, 2); // Valor repetido
    enqueue(minhaFilaFront, minhaFilaRear, 4); // Valor par
    enqueue(minhaFilaFront, minhaFilaRear, 5);
    imprimirFila(minhaFilaFront, minhaFilaRear); // Imprime o estado inicial da fila

    // Testa a fun��o peekFila
    std::cout << "Elemento no inicio: " << peekFila(minhaFilaFront) << std::endl;

    // Testa a fun��o buscarEditarElementoFila
    buscarEditarElementoFila(minhaFilaFront, minhaFilaRear, 3, 30); // Edita o valor 3 para 30
    imprimirFila(minhaFilaFront, minhaFilaRear);

    buscarEditarElementoFila(minhaFilaFront, minhaFilaRear, 99, 100); // Tenta editar um valor que n�o existe
    imprimirFila(minhaFilaFront, minhaFilaRear);

    // Testa a fun��o buscarRemoverElementoFila
    buscarRemoverElementoFila(minhaFilaFront, minhaFilaRear, 2); // Remove a primeira ocorr�ncia de 2
    imprimirFila(minhaFilaFront, minhaFilaRear);

    buscarRemoverElementoFila(minhaFilaFront, minhaFilaRear, 99); // Tenta remover um valor que n�o existe
    imprimirFila(minhaFilaFront, minhaFilaRear);

    // Testa a fun��o removerParesFila
    removerParesFila(minhaFilaFront, minhaFilaRear);
    imprimirFila(minhaFilaFront, minhaFilaRear);

    // Testa a fun��o removerRepeticoesFila
    removerRepeticoesFila(minhaFilaFront, minhaFilaRear);
    imprimirFila(minhaFilaFront, minhaFilaRear);

    deleteFila(minhaFilaFront, minhaFilaRear); // Libera a mem�ria da fila
    imprimirFila(minhaFilaFront, minhaFilaRear); // Imprime a fila vazia
    std::cout << "Fila esta vazia? " << (isEmptyFila(minhaFilaFront) ? "Sim" : "Nao") << std::endl;

    return 0;
}
