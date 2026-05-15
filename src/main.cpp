#include <iostream>
#include <unistd.h>
#include "benchmarks/sort_benchmark.cpp"

int main() {

    std::cout << "Iniciando benchmarks...\n";
    sleep(1); // Pequena pausa para o usuário ler a mensagem
    benchmarks::run_sort_benchmark();
  
    return 0;
}