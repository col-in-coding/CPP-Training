#include <cassert>
#include <vector>

class Matrix{
public:
    Matrix(int rows, int cols)
        : rows_(rows), cols_(cols), values_(rows * cols) {};
    int& operator()(int row, int col) {
        return values_[row*cols_ + col];
    }
    int operator()(int row, int col) const {
        return values_[row*cols_ + col];
    }
    // TODO: matrix addition
    // Matrix operator+(Matrix m) {
    //     Matrix
    // }
private:
    int const rows_;
    int const cols_;
    std::vector<int> values_;
};

int main(){
    Matrix matrix(2, 2);
    matrix(0, 0) = 4;
    assert(matrix(0, 0) == 4);
    // Matrix matrix2(2, 2);
    // matrix(0, 0) = 2;
    // Matrix matrix3 = matrix + matrix2;
    // assert()
}