#pragma once
#include <chrono>
#include <iostream>

namespace utils {

class Timer {
private:
  std::chrono::time_point<std::chrono::high_resolution_clock> start_time;

public:
  Timer() : start_time(std::chrono::high_resolution_clock::now()) {}

  void reset() { start_time = std::chrono::high_resolution_clock::now(); }

  long long elapsed_ms() const {

    auto end_time = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(end_time -
                                                                 start_time)
        .count();
  }

  long long elapsed_us() const {
    auto end_time = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end_time -
                                                                 start_time)
        .count();
  }

  void print_elapsed_ms(const std::string &label) const {
    std::cout << label << ": " << elapsed_ms() << "ms\n";
  }

  void print_elapsed_us(const std::string &label) const {
    std::cout << label << ": " << elapsed_us() << "µs\n";
  }
};

} // namespace utils