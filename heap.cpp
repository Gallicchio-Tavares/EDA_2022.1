#include <iostream>
using namespace std;
#define N 10

void imprimir(int A[], int valor) {
  cout << "Heap: ";
  for (int i = 0; i < N; i++) {
    if (A[i] == valor)
      cout << "\033[36m" << A[i] << "\033[m ";
    else
      cout << A[i] << " ";
  }
  cout << endl;
}

void troca(int *filho, int *pai) {
  int temp;
  temp = *filho;
  *filho = *pai;
  *pai = temp;
}

void subir(int A[], int filho) { // O(log n)
  int pai = filho / 2;           // da fórmula geeral...
  if (pai >= 0) {
    if (A[filho] > A[pai]) {
      troca(&A[filho], &A[pai]); // fazer as trocas
      subir(A, pai);
    }
  }
}

void descer(int A[], int pai, int heap) { // O(log n)
  int filhoDir = (2 * pai) + 2;
  int filhoEsq = 2 * pai + 1;
  int maior = pai;
  if (filhoDir <= heap && A[filhoDir] > A[pai])
    maior = filhoDir;
  if (filhoEsq <= heap && A[filhoEsq] > A[maior])
    maior = filhoEsq;
  if (maior != pai) {
    troca(&A[pai], &A[maior]);
    descer(A, maior, heap);
  }
}

void inserir(int A[], int valor, int posicao) { // O(log n)
  A[posicao] = valor; // vou inserir na minha última posição livre
  subir(A, posicao);  // colocar no lugar certo
  imprimir(A, valor);
}

void remover(int A[], int heap) { // O(log n)
  A[0] = A[heap - 1];             // o último elemento agr toma a posição do
  A[heap - 1] = 0;                // libero o último
  descer(A, 0, heap);
  imprimir(A, 666);
}

int main() {
  int arr[N] = {50, 30, 20, 15, 10, 8, 16}; // 6 elementos em heap inicialmente
  int meuHeap = 7, opcao;                   // onde tá a primeira posicao livre
  do {
    cout << "[0] sair\n[1] inserir \n[2] remover\n";
    cin >> opcao;
    if (opcao == 1 && meuHeap < N) {
      int num;
      cout << "Que número inserir? ";
      cin >> num;
      inserir(arr, num, meuHeap);
      meuHeap++;
    } else if (opcao == 2 && meuHeap > 0) {
      remover(arr, meuHeap);
      meuHeap--;
    }
    if (meuHeap == N) {
      cout << "\033[35mAtenção! Não há mais espaço.\033[m\n";
    }
  } while (opcao != 0);
}
