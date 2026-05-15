#pragma once
#include <iostream>
#include <string>
#include <chrono>

namespace utils {

void result_printer(std::string name_benchmark, int cpp_time, int c_time) {

  std::cout << "\n============================================================="
               "=======\n";
  std::cout << " === RESULTADOS DO BENCHMARK: " << name_benchmark << " ===\n";
  std::cout << "Tempo de gasto em C++: " << cpp_time << "µs\n";
  std::cout << "Tempo de gasto em C: " << c_time << "µs\n";

  if (cpp_time < c_time) {
    std::cout << "C++ foi mais rápido por " << (c_time - cpp_time) << "µs\n";
  } else if (c_time < cpp_time) {
    std::cout << "C foi mais rápido por " << (cpp_time - c_time) << "µs\n";
    } else {    
    std::cout << "Empate técnico! Ambos levaram o mesmo tempo.\n";
  }

  std::cout << "==============================================================="
               "=====\n";
}

} // namespace benchmarks