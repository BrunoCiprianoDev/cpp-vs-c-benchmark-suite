#include <iostream>
#include <unistd.h>
#include "benchmarks/sort_benchmark.cpp"
#include "benchmarks/memory_benchmark.cpp"
#include "benchmarks/allocation_benchmark.cpp"
#include "benchmarks/string_benchmark.cpp"

int main() {

    std::cout << "Iniciando benchmarks...\n";

    benchmarks::run_sort_benchmark();
    benchmarks::run_memory_benchmark();
    benchmarks::run_allocation_benchmark();
    benchmarks::run_string_benchmark();

    return 0;
}