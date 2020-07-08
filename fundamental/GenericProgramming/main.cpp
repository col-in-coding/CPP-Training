#include <assert.h>
#include <vector>

template <typename T> T Max(T a, T b) {
    return a > b ? a : b;
}

int main() { 
  assert(Max<int>(10, 50) == 50);
  // C++ will deduct the type input   
  assert(Max(5.7, 1.436246) == 5.7);

  std::vector<int> arr{1, 2, 3};
  assert(arr[2] == 3);

//   works on g++ -std=c++17  main.cpp
//   std::vector arr2{1, 2, 3};
//   assert(arr2[2] == 3);
}