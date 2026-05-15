#include "../utils/result_printer.cpp"
#include "../utils/timer.cpp"
#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <string>

namespace benchmarks {

void run_string_benchmark() {

  const int ITERATIONS = 1000000; // 1 milhão de concatenações

  utils::Timer timer;

 // Czão raiz
  timer.reset();
  for (int i = 0; i < ITERATIONS; i++) {
    char str[100];
    sprintf(str, "User_%d", i);
    int len = strlen(str);
    char upper[100];
    for (int j = 0; j < len; j++) {
      upper[j] = toupper(str[j]);
    }
    upper[len] = '\0';
  }
  auto c_time = timer.elapsed_ms();

  // C++ style
  timer.reset();
  for (int i = 0; i < ITERATIONS; i++) {
    std::string str = "User_" + std::to_string(i);
    std::string upper = str;
    std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
  }
  auto cpp_time = timer.elapsed_ms();

    utils::result_printer("Manipulação de strings (concatenação + uppercase)", cpp_time, c_time);
}

} // namespace benchmarks