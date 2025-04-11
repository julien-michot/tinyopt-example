
![Tinyopt-example Builds](https://github.com/julien-michot/tinyopt-example/actions/workflows/build.yml/badge.svg)

# tinyopt-example
Minimal Tinyopt project

## CMakeLists.txt

```cmake
set(CMAKE_CXX_STANDARD 20) # Minimum is c++17

find_package(Tinyopt)
find_package(Eigen3) # Only needed if Tinyopt is not found locally

add_executable(example src/example.cpp)
target_link_libraries(example PUBLIC tinyopt)
target_link_libraries(example PUBLIC Eigen3::Eigen) # needed, sometimes...
```

### Alternative using `git submodule`

The provided CMakeLists.txt is fetching Tinyopt if it's not found locally but you can also
install it using git submodules, e.g.
```shell
git submodule add https://github.com/julien-michot/tinyopt.git third_party/tinyopt
git submodule init
git submodule update --init --recursive
```
and add it to the project:

```cmake
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third_party/tinyopt)
```

## Example.cpp

Here is an example of usage of 'tinyopt' where we compute the square root of 2.

```cpp
#include <tinyopt/tinyopt.h>
using namespace tinyopt::nlls; // Default Non-Linear Least Square Optimizer

int main(int, char **argv) {
  double x = 1;
  Optimize(x, [](const auto &x) { return x * x - 2.0; });
  std::cout << "What's √2 already?\n" << x << "\n";
  return 0;
}
```

### Building

```shell
git clone https://github.com/julien-michot/tinyopt-example
cd tinyopt-example && mkdir build && cd build
cmake ..
make -j
```

### Running

```shell
./example
```