#include "../utils/result_printer.cpp"
#include "../utils/timer.cpp"
#include <cstdlib>
#include <iostream>
#include <vector>

/**
 * @author Bruno Cipriano 
 * @brief Benchmark de Acesso à Memória: Este benchmark compara o tempo gasto para 
 * acessar e preencher um array de 50 milhões de inteiros em C e C++. O objetivo é 
 * avaliar a eficiência do acesso à memória e o overhead associado a cada linguagem.
 *
 ** Implementação em C: Utiliza malloc para alocar um bloco de memória bruta e um
 * loop for para preenchimento via indexação de ponteiros.
 *
 ** Implementação em C++: Utiliza std::vector<int> com pré-alocação de tamanho,
 * explorando o gerenciamento automático de memória e operadoares de acesso da
 * STL.
 **/

namespace benchmarks {

void run_memory_benchmark() {
  const int SIZE = 50000000; // 50 milhões de inteiros

  utils::Timer timer;

  // Czão raiz
  timer.reset();
  int *c_vector = (int *)malloc(SIZE * sizeof(int));
  for (int i = 0; i < SIZE; i++) {
    c_vector[i] = i * 2; // Preenche o array com valores (pode ser qualquer
                         // coisa, aqui é só um exemplo)
  }

  long long c_time = timer.elapsed_us();

  // C++
  std::vector<int> cpp_vector(SIZE);
  timer.reset();
  for (int i = 0; i < SIZE; i++) {
    cpp_vector[i] = i * 2;
  }
  long long cpp_time = timer.elapsed_us();

  utils::result_printer("Acesso a 50 milhões de inteiros", cpp_time, c_time);

  free(c_vector);
}

} // namespace benchmarks