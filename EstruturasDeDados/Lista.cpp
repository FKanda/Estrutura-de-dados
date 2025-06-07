#include "Lista.h"    // Inclui o cabeçalho da Lista
#include <limits>     // Para usar std::numeric_limits (ex: para valores min/max em caso de erro)
#include <iostream>   // Para saída de erro (std::cerr)

// Implementação da função auxiliar: Insere um nó no final da lista
void insertEnd(Node*& head, int data) {
    Node* newNode = new Node(data); // Cria um novo nó
    if (head == nullptr) { // Se a lista estiver vazia, o novo nó é a cabeça
        head = newNode;
        return;
    }
    Node* current = head; // Começa da cabeça
    while (current->next != nullptr) { // Percorre até o último nó
        current = current->next;
    }
    current->next = newNode; // Conecta o novo nó ao final
}

// Implementação da função auxiliar: Imprime os elementos da lista
void printList(Node* lista, const std::string& name) {
    std::cout << name << ": ["; // Imprime o nome da lista
    Node* current = lista;      // Começa da cabeça
    while (current != nullptr) { // Percorre todos os nós
        std::cout << current->data; // Imprime o dado do nó
        if (current->next != nullptr) { // Adiciona vírgula e espaço se não for o último elemento
            std::cout << ", ";
        }
        current = current->next; // Move para o próximo nó
    }
    std::cout << "]" << std::endl; // Fecha colchetes e nova linha
}

// Implementação da função auxiliar: Libera a memória alocada para a lista
void deleteList(Node*& head) {
    Node* current = head;     // Começa da cabeça
    Node* nextNode;           // Variável temporária para guardar o próximo nó
    while (current != nullptr) { // Enquanto houver nós
        nextNode = current->next; // Salva o ponteiro para o próximo nó
        delete current;           // Libera a memória do nó atual
        current = nextNode;       // Move para o próximo nó salvo
    }
    head = nullptr; // Garante que a cabeça da lista seja nula após a exclusão
}

// 1.1 Função que retorna o menor elemento da lista
int minLista(Node* lista) {
    if (lista == nullptr) { // Verifica se a lista está vazia
        std::cerr << "Erro: Lista vazia. Nao e possivel encontrar o menor elemento." << std::endl;
        // Retorna o maior valor possível para int, indicando um erro ou valor inválido
        return std::numeric_limits<int>::max();
    }

    int minVal = lista->data; // Inicializa o menor valor com o dado do primeiro nó
    Node* current = lista->next; // Começa do segundo nó
    while (current != nullptr) { // Percorre o restante da lista
        if (current->data < minVal) { // Se o dado atual for menor que o 'minVal'
            minVal = current->data;   // Atualiza 'minVal'
        }
        current = current->next;      // Move para o próximo nó
    }
    return minVal; // Retorna o menor valor encontrado
}

// 1.2 Função que retorna o maior elemento da lista
int maxLista(Node* lista) {
    if (lista == nullptr) { // Verifica se a lista está vazia
        std::cerr << "Erro: Lista vazia. Nao e possivel encontrar o maior elemento." << std::endl;
        // Retorna o menor valor possível para int, indicando um erro ou valor inválido
        return std::numeric_limits<int>::min();
    }

    int maxVal = lista->data; // Inicializa o maior valor com o dado do primeiro nó
    Node* current = lista->next; // Começa do segundo nó
    while (current != nullptr) { // Percorre o restante da lista
        if (current->data > maxVal) { // Se o dado atual for maior que o 'maxVal'
            maxVal = current->data;   // Atualiza 'maxVal'
        }
        current = current->next;      // Move para o próximo nó
    }
    return maxVal; // Retorna o maior valor encontrado
}

// 1.3 Função que retorna a média dos elementos da lista
double mediaLista(Node* lista) {
    if (lista == nullptr) { // Verifica se a lista está vazia
        std::cerr << "Erro: Lista vazia. Nao e possivel calcular a media." << std::endl;
        return 0.0; // Retorna 0.0 para lista vazia
    }

    int sum = 0;   // Soma dos elementos
    int count = 0; // Contagem de elementos
    Node* current = lista; // Começa da cabeça
    while (current != nullptr) { // Percorre a lista
        sum += current->data; // Adiciona o dado à soma
        count++;              // Incrementa a contagem
        current = current->next; // Move para o próximo nó
    }
    // Calcula a média, garantindo que a divisão seja de ponto flutuante
    return static_cast<double>(sum) / count;
}

// 1.4 Função que retorna o número de elementos da lista
int lenLista(Node* lista) {
    int count = 0;         // Inicializa a contagem
    Node* current = lista; // Começa da cabeça
    while (current != nullptr) { // Percorre a lista
        count++;              // Incrementa a contagem para cada nó
        current = current->next; // Move para o próximo nó
    }
    return count; // Retorna o número total de elementos
}

// 2. Função que concatena duas listas L1 e L2
Node* appendLista(Node* L1, Node* L2) {
    if (L1 == nullptr) { // Se L1 for vazia, L2 é a lista resultante
        return L2;
    }
    if (L2 == nullptr) { // Se L2 for vazia, L1 permanece a mesma
        return L1;
    }

    Node* current = L1; // Começa da cabeça de L1
    while (current->next != nullptr) { // Percorre L1 até o último nó
        current = current->next;
    }
    current->next = L2; // Conecta o último nó de L1 ao primeiro nó de L2
    return L1; // Retorna a cabeça da lista L1 (que agora inclui L2)
}

// 3. Função que inverte uma lista
Node* reverseLista(Node* lista) {
    Node* prev = nullptr;    // Ponteiro para o nó anterior (inicialmente nulo)
    Node* current = lista;   // Ponteiro para o nó atual (começa na cabeça da lista)
    Node* nextNode = nullptr; // Ponteiro temporário para o próximo nó

    while (current != nullptr) { // Percorre a lista
        nextNode = current->next; // Salva o ponteiro para o próximo nó antes de modificá-lo
        current->next = prev;     // Inverte o ponteiro do nó atual para apontar para o anterior
        prev = current;           // Move 'prev' para o nó atual
        current = nextNode;       // Move 'current' para o próximo nó original
    }
    return prev; // 'prev' agora aponta para a nova cabeça da lista invertida
}

// 4. Função que recebe duas listas L1 e L2 e retorna "1" se L2 for uma sublista de L1 ou "0" caso contrário.
int isSubLista(Node* L1, Node* L2) {
    if (L2 == nullptr) { // Uma lista vazia é sempre considerada uma sublista
        return 1;
    }
    if (L1 == nullptr) { // Se L1 é vazia e L2 não é (já tratada no caso L2==nullptr), L2 não pode ser sublista
        return 0;
    }

    Node* ptr1 = L1; // Ponteiro para percorrer L1
    Node* ptr2 = L2; // Ponteiro para percorrer L2 (sublista)

    while (ptr1 != nullptr) { // Percorre a lista principal L1
        // Se o elemento atual de L1 coincide com o primeiro de L2,
        // inicie a comparação da potencial sublista
        if (ptr1->data == ptr2->data) {
            Node* temp1 = ptr1; // Ponteiro temporário para L1
            Node* temp2 = ptr2; // Ponteiro temporário para L2

            // Compara os elementos enquanto houver correspondência
            while (temp1 != nullptr && temp2 != nullptr && temp1->data == temp2->data) {
                temp1 = temp1->next; // Avança em L1
                temp2 = temp2->next; // Avança em L2
            }
            // Se 'temp2' se tornou nulo, significa que toda a L2 foi encontrada sequencialmente em L1
            if (temp2 == nullptr) {
                return 1; // L2 é uma sublista de L1
            }
        }
        ptr1 = ptr1->next; // Move para o próximo nó em L1
    }
    return 0; // L2 não foi encontrada como sublista em L1
