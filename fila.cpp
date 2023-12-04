#include <iostream>

using namespace std;

// Definição da estrutura de uma célula (nó) da fila
typedef struct celula {
    int conteudo;     // Conteúdo da célula
    celula *prox;      // Ponteiro para a próxima célula na fila
} no;

// Função para criar uma fila vazia e retorna o ponteiro para a cabeça
celula* criaFila() {
    celula *cabeca = new celula;   // Aloca uma célula para a cabeça da fila
    cabeca->prox = nullptr;        // Inicializa o ponteiro para a próxima célula como nulo
    return cabeca;                 // Retorna o ponteiro para a cabeça da fila
}

// Função para inserir um elemento no final da fila
celula* insere(celula* cabeca, int valor) {
    celula* novaCelula = new celula;   // Aloca uma nova célula para o novo elemento
    novaCelula->conteudo = valor;      // Atribui o valor ao conteúdo da nova célula
    novaCelula->prox = nullptr;        // Inicializa o ponteiro para a próxima célula como nulo

    // Se a fila estiver vazia, a nova célula se torna a próxima da cabeça
    // Senão, percorre a fila até o final e insere a nova célula lá
    (cabeca->prox == nullptr) ? cabeca->prox = novaCelula : [&]() {
        celula* p = cabeca->prox;
        while (p->prox != nullptr) {
            p = p->prox;
        }
        p->prox = novaCelula;
    }();

    return cabeca;   // Retorna o ponteiro para a cabeça da fila
}

// Função para imprimir os elementos da fila
void imprime(celula *cabeca) {
    celula *p = cabeca->prox;   // Inicia a partir da primeira célula (após a cabeça)
    while (p != nullptr) {
        cout << p->conteudo << " ";   // Imprime o conteúdo da célula
        p = p->prox;                  // Move para a próxima célula
    }
    cout << endl;
}

// Função para remover um número especificado de elementos do início da fila
void saidaFila(celula *cabeca, int elementos) {
    // Remove os primeiros "elementos" elementos da fila, se existirem
    for (int i = 0; i < elementos && cabeca->prox != nullptr; ++i) {
        celula *saida = cabeca->prox;
        cabeca->prox = saida->prox;
        delete saida;   // Libera a célula removida da memória
    }
    // Se a fila estiver vazia, imprime uma mensagem indicando que está vazia
    (cabeca->prox == nullptr) ? cout << "A fila está vazia." << endl : cout << "";
}

// Função para liberar toda a memória alocada para a fila
void liberarFila(celula *cabeca) {
    celula *p = cabeca->prox;   // Inicia a partir da primeira célula (após a cabeça)
    while (p != nullptr) {
        celula *temp = p;
        p = p->prox;
        delete temp;   // Libera a célula atual da memória
    }
    delete cabeca;   // Libera a cabeça da fila da memória
}

int main() {
    celula *cabeca = criaFila();   // Cria uma fila vazia e obtém o ponteiro para a cabeça

    // Inserir elementos na fila
    int elementos[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; ++i) {
        cabeca = insere(cabeca, elementos[i]);
    }

    cout << "Fila antes da remoção: ";
    imprime(cabeca);

    // Remover os dois primeiros elementos
    int elementosARemover = 2;
    saidaFila(cabeca, elementosARemover);

    cout << "Fila após a remoção: ";
    imprime(cabeca);

    liberarFila(cabeca);   // Libera toda a memória alocada para a fila

    return 0;
}
