#include "../utils/result_printer.cpp"
#include "../utils/timer.cpp"
#include <cstdlib>
#include <iostream>
#include <vector>

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

  auto c_time = timer.elapsed_us();

  // C++
  std::vector<int> cpp_vector(SIZE);
  timer.reset();
  for (int i = 0; i < SIZE; i++) {
    cpp_vector[i] = i * 2;
  }
  auto cpp_time = timer.elapsed_ms();

  utils::result_printer("Acesso a 50 milhões de inteiros", cpp_time, c_time);

  free(c_vector);
}

} // namespace benchmarks