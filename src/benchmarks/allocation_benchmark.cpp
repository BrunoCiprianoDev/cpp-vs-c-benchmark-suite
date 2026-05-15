#include "../utils/timer.cpp"
#include "../utils/result_printer.cpp"
#include <cstdlib>
#include <iostream>
#include <vector>

namespace benchmarks {

/**
* @author Bruno Cipriano 
* @brief Benchmark de Alocação: Este benchmark compara o tempo gasto para alocar 
* e preencher 1 milhão de blocos de 1KB em C e C++. O objetivo é avaliar a eficiência 
* do processo de alocação e o overhead associado a cada linguagem.
*
** Implementação em C: Utiliza malloc para alocar blocos de memória bruta e um loop
* for para preenchimento via indexação de ponteiros, seguido de free para liberar a memória.
*
**  Implementação em C++: Utiliza std::vector<int> com pré-alocação   
* de tamanho, explorando o gerenciamento automático de memória e operadoares de acesso da STL.
*/


    void run_allocation_benchmark() {

  const int ITERATIONS = 1000000; // 1 milhão de alocações
  const int BLOCK_SIZE = 1024;    // 1 KB por alocação

  utils::Timer timer;

  // Czão raíz
  timer.reset();
  for (int i = 0; i < ITERATIONS; i++) {
    int *ptr = (int *)malloc(BLOCK_SIZE * sizeof(int));
    for (int j = 0; j < BLOCK_SIZE; j++) {
      ptr[j] = j;
    }
    free(ptr);
  }
  long long c_time = timer.elapsed_us();

  // C++
  timer.reset();
  std::vector<int> vec;
  vec.reserve(BLOCK_SIZE);
  for (int i = 0; i < ITERATIONS; i++) {
    vec.clear();
    for (int j = 0; j < BLOCK_SIZE; j++) {
      vec.push_back(j);
    }
  }
  long long cpp_time = timer.elapsed_us();

  utils::result_printer("Alocação e preenchimento de 1 milhão de blocos de 1KB", cpp_time, c_time);

}

} // namespace benchmarks