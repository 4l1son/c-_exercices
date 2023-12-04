#include <iostream>

using namespace std;

// Definição da estrutura de uma célula (nó) da pilha
typedef struct celula {
    int conteudo;     // Conteúdo da célula
    celula *prox;      // Ponteiro para a próxima célula na pilha
} no;

// Função para criar uma pilha vazia e retorna o ponteiro para a cabeça
celula* criaPilha() {
    celula *cabeca = new celula;   // Aloca uma célula para a cabeça da pilha
    cabeca->prox = nullptr;        // Inicializa o ponteiro para a próxima célula como nulo
    return cabeca;                 // Retorna o ponteiro para a cabeça da pilha
}

// Função para inserir um elemento no topo da pilha
celula* insere(celula* cabeca, int valor) {
    celula* novaCelula = new celula;   // Aloca uma nova célula para o novo elemento
    novaCelula->conteudo = valor;      // Atribui o valor ao conteúdo da nova célula
    novaCelula->prox = cabeca->prox;   // A nova célula aponta para o antigo topo da pilha
    cabeca->prox = novaCelula;         // A cabeça da pilha aponta para a nova célula (novo topo)
    return cabeca;                     // Retorna o ponteiro para a cabeça da pilha
}

// Função para imprimir os elementos da pilha
void imprime(celula *cabeca) {
    celula *p = cabeca->prox;   // Inicia a partir do primeiro elemento (após a cabeça)
    while (p != nullptr) {
        cout << p->conteudo << " ";   // Imprime o conteúdo da célula
        p = p->prox;                  // Move para a próxima célula
    }
    cout << endl;
}

// Função para remover um número especificado de elementos do topo da pilha
void sairdaPilha(celula *cabeca, int elementos) {
    celula *valor = cabeca->prox;   // Inicia a partir do primeiro elemento (topo da pilha)
    int count = 0;

    // Remove os primeiros "elementos" elementos da pilha, se existirem
    while (valor != nullptr && count < elementos) {
        celula *saida = valor;
        valor = valor->prox;
        delete saida;   // Libera a célula removida da memória
        count++;
    }

    cabeca->prox = valor;  // Atualiza o próximo da cabeça após a remoção
}

// Função para liberar toda a memória alocada para a pilha
void liberarPilha(celula *cabeca) {
    celula *p = cabeca->prox;   // Inicia a partir do primeiro elemento (após a cabeça)
    while (p != nullptr) {
        celula *temp = p;
        p = p->prox;
        delete temp;   // Libera a célula atual da memória
    }
    delete cabeca;   // Libera a cabeça da pilha da memória
}

int main() {
    celula *cabeca = criaPilha();   // Cria uma pilha vazia e obtém o ponteiro para a cabeça

    // Inserir elementos na pilha
    int elementos[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; ++i) {
        cabeca = insere(cabeca, elementos[i]);
    }

    cout << "Pilha antes da remoção: ";
    imprime(cabeca);

    // Remover os dois primeiros elementos
    int elementosARemover = 2;
    sairdaPilha(cabeca, elementosARemover);

    cout << "Pilha após a remoção: ";
    imprime(cabeca);

    liberarPilha(cabeca);   // Libera toda a memória alocada para a pilha

    return 0;
}
