#include <iostream>
#include <unistd.h>
#include "benchmarks/sort_benchmark.cpp"
#include "benchmarks/memory_benchmark.cpp"

int main() {

    std::cout << "Iniciando benchmarks...\n";

    benchmarks::run_sort_benchmark();
    benchmarks::run_memory_benchmark();

    return 0;
}