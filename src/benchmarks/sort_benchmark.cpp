#include "../utils/timer.cpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

namespace benchmarks {

void run_sort_benchmark() {

  const int SIZE = 1000000;

  std::cout << "Gerando dados aleatórios...\n";

  std::vector<int> cpp_vector(SIZE); // Vetor para C++

  int *c_vector = (int *)malloc(SIZE * sizeof(int)); // Vetor pro Czão raiz

  // O rand() gera a mesma sequência de números para os dois arrays
  srand(42);

  for (int i = 0; i < SIZE; ++i) {
    int random_value = rand();    // Gera um número aleatório
    cpp_vector[i] = random_value; // Preenche o array do C++
    c_vector[i] = random_value;   // Preenche o array do C
  }

  utils::Timer timer;

  timer.reset();
  std::sort(cpp_vector.begin(), cpp_vector.end());
  auto cpp_time = timer.elapsed_us();

  timer.reset();
  /**
   * @author Bruno Cipriano
   * @brief Explicação do funcionamento do qsort (C Standard Library):
   * * O qsort implementa o algoritmo QuickSort (ou variações como IntroSort).
   * Diferente do std::sort do C++, ele é agnóstico ao tipo de dado
   * (Type-Agnostic). <--- Não conhece o tipo de dado que está ordenando, seja
   int, float ou struct.
   * * Como ele funciona:
   * 1. Base: Recebe o endereço inicial do array (void*).
   * 2. Itens/Size: Precisa do número de elementos e do tamanho em bytes de cada
   * um para navegar na memória (aritmética de ponteiros manual).
   * 3. Callback: O "coração" do qsort é o ponteiro de função (compar). Como o
   * qsort não sabe se está ordenando inteiros ou structs, ele interrompe sua
   * execução e chama essa função externa toda vez que precisa comparar dois
   * elementos.
   * * Nota de Performance: Esse "pula-pula" (overhead) de chamar uma função via
   * ponteiro milhões de vezes impede otimizações do compilador (como o
   * inlining), tornando-o geralmente mais lento que o std::sort do C++.
   **
   ** O GRANDE DESSE ALGORITMO É:
   $O(n \log n)$ com sorte e $O(n^2)$ (TÃO MERDA QUANTO O BUBLESORT) no pior
   caso, enquanto o std::sort do C++ é otimizado para garantir $O(n \log n)$
   mesmo no pior cenário.
   */
  qsort(c_vector, SIZE, sizeof(int), [](const void *a, const void *b) {
    // Converte os ponteiros genéricos (void*) para inteiros e subtrai
    //                       ^^^^^^^^^ -> A tal "Agnosticidade" do qsort
    return *(int *)a - *(int *)b;
  });

  auto c_time = timer.elapsed_us();

  std::cout << "Tempo de ordenação em C++: " << cpp_time << "µs\n";
  std::cout << "Tempo de ordenação em C: " << c_time << "µs\n";

  if (cpp_time < c_time) {
    std::cout << "C++ foi mais rápido por " << (c_time - cpp_time) << "µs\n";
  } else if (c_time < cpp_time) {
    std::cout << "C foi mais rápido por " << (cpp_time - c_time) << "µs\n";
  }

  free(c_vector);
}

} // namespace benchmarks