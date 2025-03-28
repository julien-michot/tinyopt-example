
![Tinyopt-example Builds](https://github.com/julien-michot/tinyopt-example/actions/workflows/build.yml/badge.svg)

# tinyopt-example
Minimal Tinyopt project

## CMakeLists.txt

```cmake
set(CMAKE_CXX_STANDARD 20)

find_package(Eigen3 REQUIRED NO_MODULE)
find_package(Tinyopt)

add_executable(example src/example.cpp)
target_link_libraries(example PUBLIC Eigen3::Eigen tinyopt)
```


## Example.cpp

Here is an example of usage of 'tinyopt' where we compute the square root of 2.

```cpp
#include <tinyopt/tinyopt.h>

int main(int, char **argv) {
  double x = 1;
  tinyopt::Optimize(x, [](const auto &x) { return x * x - 2.0; });
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