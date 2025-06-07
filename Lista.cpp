#include "Lista.h"    // Inclui o cabe�alho da Lista
#include <limits>     // Para usar std::numeric_limits (ex: para valores min/max em caso de erro)
#include <iostream>   // Para sa�da de erro (std::cerr)

// Implementa��o da fun��o auxiliar: Insere um n� no final da lista
void insertEnd(Node*& head, int data) {
    Node* newNode = new Node(data); // Cria um novo n�
    if (head == nullptr) { // Se a lista estiver vazia, o novo n� � a cabe�a
        head = newNode;
        return;
    }
    Node* current = head; // Come�a da cabe�a
    while (current->next != nullptr) { // Percorre at� o �ltimo n�
        current = current->next;
    }
    current->next = newNode; // Conecta o novo n� ao final
}

// Implementa��o da fun��o auxiliar: Imprime os elementos da lista
void printList(Node* lista, const std::string& name) {
    std::cout << name << ": ["; // Imprime o nome da lista
    Node* current = lista;      // Come�a da cabe�a
    while (current != nullptr) { // Percorre todos os n�s
        std::cout << current->data; // Imprime o dado do n�
        if (current->next != nullptr) { // Adiciona v�rgula e espa�o se n�o for o �ltimo elemento
            std::cout << ", ";
        }
        current = current->next; // Move para o pr�ximo n�
    }
    std::cout << "]" << std::endl; // Fecha colchetes e nova linha
}

// Implementa��o da fun��o auxiliar: Libera a mem�ria alocada para a lista
void deleteList(Node*& head) {
    Node* current = head;     // Come�a da cabe�a
    Node* nextNode;           // Vari�vel tempor�ria para guardar o pr�ximo n�
    while (current != nullptr) { // Enquanto houver n�s
        nextNode = current->next; // Salva o ponteiro para o pr�ximo n�
        delete current;           // Libera a mem�ria do n� atual
        current = nextNode;       // Move para o pr�ximo n� salvo
    }
    head = nullptr; // Garante que a cabe�a da lista seja nula ap�s a exclus�o
}

// 1.1 Fun��o que retorna o menor elemento da lista
int minLista(Node* lista) {
    if (lista == nullptr) { // Verifica se a lista est� vazia
        std::cerr << "Erro: Lista vazia. Nao e possivel encontrar o menor elemento." << std::endl;
        // Retorna o maior valor poss�vel para int, indicando um erro ou valor inv�lido
        return std::numeric_limits<int>::max();
    }

    int minVal = lista->data; // Inicializa o menor valor com o dado do primeiro n�
    Node* current = lista->next; // Come�a do segundo n�
    while (current != nullptr) { // Percorre o restante da lista
        if (current->data < minVal) { // Se o dado atual for menor que o 'minVal'
            minVal = current->data;   // Atualiza 'minVal'
        }
        current = current->next;      // Move para o pr�ximo n�
    }
    return minVal; // Retorna o menor valor encontrado
}

// 1.2 Fun��o que retorna o maior elemento da lista
int maxLista(Node* lista) {
    if (lista == nullptr) { // Verifica se a lista est� vazia
        std::cerr << "Erro: Lista vazia. Nao e possivel encontrar o maior elemento." << std::endl;
        // Retorna o menor valor poss�vel para int, indicando um erro ou valor inv�lido
        return std::numeric_limits<int>::min();
    }

    int maxVal = lista->data; // Inicializa o maior valor com o dado do primeiro n�
    Node* current = lista->next; // Come�a do segundo n�
    while (current != nullptr) { // Percorre o restante da lista
        if (current->data > maxVal) { // Se o dado atual for maior que o 'maxVal'
            maxVal = current->data;   // Atualiza 'maxVal'
        }
        current = current->next;      // Move para o pr�ximo n�
    }
    return maxVal; // Retorna o maior valor encontrado
}

// 1.3 Fun��o que retorna a m�dia dos elementos da lista
double mediaLista(Node* lista) {
    if (lista == nullptr) { // Verifica se a lista est� vazia
        std::cerr << "Erro: Lista vazia. Nao e possivel calcular a media." << std::endl;
        return 0.0; // Retorna 0.0 para lista vazia
    }

    int sum = 0;   // Soma dos elementos
    int count = 0; // Contagem de elementos
    Node* current = lista; // Come�a da cabe�a
    while (current != nullptr) { // Percorre a lista
        sum += current->data; // Adiciona o dado � soma
        count++;              // Incrementa a contagem
        current = current->next; // Move para o pr�ximo n�
    }
    // Calcula a m�dia, garantindo que a divis�o seja de ponto flutuante
    return static_cast<double>(sum) / count;
}

// 1.4 Fun��o que retorna o n�mero de elementos da lista
int lenLista(Node* lista) {
    int count = 0;         // Inicializa a contagem
    Node* current = lista; // Come�a da cabe�a
    while (current != nullptr) { // Percorre a lista
        count++;              // Incrementa a contagem para cada n�
        current = current->next; // Move para o pr�ximo n�
    }
    return count; // Retorna o n�mero total de elementos
}

// 2. Fun��o que concatena duas listas L1 e L2
Node* appendLista(Node* L1, Node* L2) {
    if (L1 == nullptr) { // Se L1 for vazia, L2 � a lista resultante
        return L2;
    }
    if (L2 == nullptr) { // Se L2 for vazia, L1 permanece a mesma
        return L1;
    }

    Node* current = L1; // Come�a da cabe�a de L1
    while (current->next != nullptr) { // Percorre L1 at� o �ltimo n�
        current = current->next;
    }
    current->next = L2; // Conecta o �ltimo n� de L1 ao primeiro n� de L2
    return L1; // Retorna a cabe�a da lista L1 (que agora inclui L2)
}

// 3. Fun��o que inverte uma lista
Node* reverseLista(Node* lista) {
    Node* prev = nullptr;    // Ponteiro para o n� anterior (inicialmente nulo)
    Node* current = lista;   // Ponteiro para o n� atual (come�a na cabe�a da lista)
    Node* nextNode = nullptr; // Ponteiro tempor�rio para o pr�ximo n�

    while (current != nullptr) { // Percorre a lista
        nextNode = current->next; // Salva o ponteiro para o pr�ximo n� antes de modific�-lo
        current->next = prev;     // Inverte o ponteiro do n� atual para apontar para o anterior
        prev = current;           // Move 'prev' para o n� atual
        current = nextNode;       // Move 'current' para o pr�ximo n� original
    }
    return prev; // 'prev' agora aponta para a nova cabe�a da lista invertida
}

// 4. Fun��o que recebe duas listas L1 e L2 e retorna "1" se L2 for uma sublista de L1 ou "0" caso contr�rio.
int isSubLista(Node* L1, Node* L2) {
    if (L2 == nullptr) { // Uma lista vazia � sempre considerada uma sublista
        return 1;
    }
    if (L1 == nullptr) { // Se L1 � vazia e L2 n�o � (j� tratada no caso L2==nullptr), L2 n�o pode ser sublista
        return 0;
    }

    Node* ptr1 = L1; // Ponteiro para percorrer L1
    Node* ptr2 = L2; // Ponteiro para percorrer L2 (sublista)

    while (ptr1 != nullptr) { // Percorre a lista principal L1
        // Se o elemento atual de L1 coincide com o primeiro de L2,
        // inicie a compara��o da potencial sublista
        if (ptr1->data == ptr2->data) {
            Node* temp1 = ptr1; // Ponteiro tempor�rio para L1
            Node* temp2 = ptr2; // Ponteiro tempor�rio para L2

            // Compara os elementos enquanto houver correspond�ncia
            while (temp1 != nullptr && temp2 != nullptr && temp1->data == temp2->data) {
                temp1 = temp1->next; // Avan�a em L1
                temp2 = temp2->next; // Avan�a em L2
            }
            // Se 'temp2' se tornou nulo, significa que toda a L2 foi encontrada sequencialmente em L1
            if (temp2 == nullptr) {
                return 1; // L2 � uma sublista de L1
            }
        }
        ptr1 = ptr1->next; // Move para o pr�ximo n� em L1
    }
    return 0; // L2 n�o foi encontrada como sublista em L1
