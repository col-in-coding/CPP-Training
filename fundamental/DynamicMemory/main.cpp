/**
 * Allocate memory at the run time
 * Using "new" and "delete"
 */
#include <iostream>

using namespace std;

int main() {
  int *int_ptr {nullptr};
  int_ptr = new int;
  cout << int_ptr << endl;
  // if no delete, we lost the only way to get this storage,
  // which called "Memory Leak"
  delete int_ptr;

  size_t size {0};
  double *temp_ptr {nullptr};
  cout << "How many temps: " << endl;
  cin >> size;
  temp_ptr = new double [size];
  cout << temp_ptr << endl;
  delete [] temp_ptr;


  return 0;
}