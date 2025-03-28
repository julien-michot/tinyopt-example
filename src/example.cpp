/// This is free and unencumbered software released into the public domain.
/// Example of usage of 'tinyopt' and compute the square root of 2.

#include <tinyopt/tinyopt.h>

int main(int, char **argv) {

  double x = 1;
  auto loss = [](const auto &x) { return x * x - 2.0; };

  tinyopt::Options options;
  const auto &out = tinyopt::Optimize(x, loss, options);

  std::cout << "What's √2 already?\n" << x << "\n";
  return 0;
}