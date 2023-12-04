#include <iostream>
#include <vector>

using namespace std;

// Função para exibir um vetor
void printArray(const vector<int>& arr, const string& label) {
    cout << label << ": ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        // Encontra o índice do menor elemento na parte não ordenada do vetor
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Troca o elemento mínimo com o primeiro elemento não ordenado
        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        // Move os elementos maiores que a chave para a frente
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // Insere a chave na posição correta
        arr[j + 1] = key;
    }
}

// Shell Sort
void shellSort(vector<int>& arr) {
    int n = arr.size();
    // Define o espaçamento inicial
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Aplica o insertion sort com o espaçamento definido
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            // Move os elementos maiores que a chave para a frente
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            // Insere a chave na posição correta
            arr[j] = temp;
        }
    }
}

// Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    // Divide o vetor em duas partes e mescla as partes ordenadamente
    vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    // Mescla as duas partes ordenadamente
    while (i < L.size() && j < R.size()) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }

    // Adiciona quaisquer elementos restantes de L e R
    while (i < L.size()) arr[k++] = L[i++];
    while (j < R.size()) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Encontra o ponto médio e divide o vetor em duas partes
        int mid = left + (right - left) / 2;
        // Recursivamente aplica o merge sort para cada parte
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        // Mescla as partes ordenadamente
        merge(arr, left, mid, right);
    }
}

// Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    // Coloca os elementos menores que o pivô à esquerda e os maiores à direita
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) swap(arr[++i], arr[j]);
    }

    // Coloca o pivô na posição correta
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Encontra o pivô e coloca os elementos em torno dele em posições corretas
        int pi = partition(arr, low, high);
        // Recursivamente aplica o quick sort para as duas partes
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    printArray(arr, "Original array");

    // Aplica o Selection Sort e imprime o resultado
    selectionSort(arr);
    printArray(arr, "Selection Sort");

    // Reinicializa o vetor e aplica o Insertion Sort, depois imprime o resultado
    arr = {64, 34, 25, 12, 22, 11, 90};
    insertionSort(arr);
    printArray(arr, "Insertion Sort");

    // Reinicializa o vetor e aplica o Shell Sort, depois imprime o resultado
    arr = {64, 34, 25, 12, 22, 11, 90};
    shellSort(arr);
    printArray(arr, "Shell Sort");

    // Reinicializa o vetor e aplica o Merge Sort, depois imprime o resultado
    arr = {64, 34, 25, 12, 22, 11, 90};
    mergeSort(arr, 0, arr.size() - 1);
    printArray(arr, "Merge Sort");

    // Reinicializa o vetor e aplica o Quick Sort, depois imprime o resultado
    arr = {64, 34, 25, 12, 22, 11, 90};
    quickSort(arr, 0, arr.size() - 1);
    printArray(arr, "Quick Sort");

    return 0;
}
