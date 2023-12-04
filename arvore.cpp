#include <iostream>

// Definição de uma estrutura (struct) para representar um nó da árvore
struct Node {
    int key;        // Valor armazenado no nó
    Node* left;     // Ponteiro para o nó filho à esquerda
    Node* right;    // Ponteiro para o nó filho à direita

    // Construtor para inicializar um nó com um valor específico
    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

// Protótipo da função para encontrar o nó com o menor valor em uma subárvore
Node* minValueNode(Node* node);

// Função para inserir um novo valor na árvore
Node* insert(Node* node, int key) {
    if (!node) return new Node(key);   // Se o nó for nulo, cria um novo nó com o valor
    if (key < node->key)               // Se o valor for menor que a chave do nó atual
        node->left = insert(node->left, key);   // Insere na subárvore à esquerda
    else if (key > node->key)          // Se o valor for maior que a chave do nó atual
        node->right = insert(node->right, key); // Insere na subárvore à direita
    return node;   // Retorna o nó atualizado
}

// Função para remover um valor da árvore
Node* remove(Node* node, int key) {
    if (!node) return node;    // Se o nó for nulo, retorna sem fazer nada
    if (key < node->key)       // Se o valor for menor que a chave do nó atual
        node->left = remove(node->left, key);    // Remove da subárvore à esquerda
    else if (key > node->key)  // Se o valor for maior que a chave do nó atual
        node->right = remove(node->right, key);  // Remove da subárvore à direita
    else {
        if (!node->left) {      // Se o nó não tem filho à esquerda
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {  // Se o nó não tem filho à direita
            Node* temp = node->left;
            delete node;
            return temp;
        }
        // Se o nó tem ambos os filhos, substitui pelo nó com o menor valor na subárvore à direita
        Node* temp = minValueNode(node->right);
        node->key = temp->key;
        node->right = remove(node->right, temp->key);
    }
    return node;   // Retorna o nó atualizado
}

// Função auxiliar para encontrar o nó com o menor valor em uma subárvore
Node* minValueNode(Node* node) {
    while (node->left) node = node->left;   // Percorre para a extrema esquerda
    return node;
}

// Função para percorrer a árvore em ordem e imprimir os valores (in-order traversal)
void inorderTraversal(Node* node) {
    if (node) {
        inorderTraversal(node->left);    // Percorre a subárvore à esquerda
        std::cout << node->key << " ";   // Imprime o valor do nó atual
        inorderTraversal(node->right);   // Percorre a subárvore à direita
    }
}

// Função principal
int main() {
    Node* root = nullptr;   // Inicializa a árvore como vazia

    // Insere valores na árvore
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    // Imprime a árvore antes da remoção
    std::cout << "Árvore (in-order): ";
    inorderTraversal(root);
    std::cout << std::endl;

    // Remove um valor da árvore
    root = remove(root, 5);

    // Imprime a árvore após a remoção
    std::cout << "Árvore após remoção: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
