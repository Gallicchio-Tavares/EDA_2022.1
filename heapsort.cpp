#include <iostream>
using namespace std;
#define T 10

void troca(int *a, int *b) {
  int aux;
  aux = *a;
  *a = *b;
  *b = aux;
}

void descer(int A[], int i, int q) { // O(log n)
  int d = 2 * i + 1;
  int e = 2 * i;
  int maior = i;
  if (d <= q && A[d] > A[i])
    maior = d;
  if (e <= q && A[e] > A[maior])
    maior = e;
  if (maior != i) {
    troca(&A[i], &A[maior]);
    descer(A, maior, q);
  }
}

void heap(int A[], int t) {
  for (int i = (t / 2); i >= 0; i--)
    descer(A, i, t - 1);
  cout << "Array em um heap: ";    
  for (int i = 0; i < T; i++) {
    cout << A[i] << " "; // imprimir o heap
  }
  cout << endl;
}

void heapsort(int A[], int n) {
  int i;
  heap(A, T); // se não for um heap, transformar em um
  for (i = n - 1; i >= 1; i--) {
    troca(&A[0], &A[i]);
    descer(A, 0, i - 1);
  }
}

int main() {
  int A[T] = {50, 2, 75, 8, 10, 6, 15, 4, 9, 3}; // não é um heap
  int i;
  cout << "Array desorganizado: ";
  for (i = 0; i < T; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
  heapsort(A, T);
  cout << "Array organizado: ";
  for (i = 0; i < T; i++) {
    cout << A[i] << " ";
  }
}
