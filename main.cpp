
#include <iostream>
#include <fstream>
using namespace std;
const int SIZE = 4;

class Matrix {
public:
    int matrix_size;
    double** matrix_data;

    Matrix(int size = 0) : matrix_size(size) {
        matrix_data = new double*[matrix_size];
        for (int i = 0; i < matrix_size; ++i) {
            matrix_data[i] = new double[matrix_size];
        }
    }

    Matrix& operator=(const Matrix& other) {
        if (this == &other) {
            return *this;
        }

        for (int i = 0; i < matrix_size; ++i) {
            delete[] matrix_data[i];
        }
        delete[] matrix_data;

        matrix_size = other.matrix_size;

        matrix_data = new double*[matrix_size];
        for (int i = 0; i < matrix_size; ++i) {
            matrix_data[i] = new double[matrix_size];
            for (int j = 0; j < matrix_size; ++j) {
                matrix_data[i][j] = other.matrix_data[i][j];
            }
        }

        return *this;
    }

    ~Matrix() {
        for (int i = 0; i < matrix_size; ++i) {
            delete[] matrix_data[i];
        }
        delete[] matrix_data;
    }
};


void read_matrix_from_file(const string& file_name, Matrix& matrix_1, Matrix& matrix_2) {
    // TODO: Read matrix data from the file
    //    Make sure to handle potential errors and invalid input
    ifstream file(file_name);
    if(file.is_open()){
        file >> matrix_1.matrix_size;
        matrix_2.matrix_size = matrix_1.matrix_size;
        for(int i = 0; i<matrix_1.matrix_size; i++){
            for(int j = 0; j<matrix_1.matrix_size; j++){
                file >> matrix_1.matrix_data[i][j];
            }
        }
        for(int i = 0; i<matrix_2.matrix_size; i++){
            for(int j = 0; j<matrix_2.matrix_size; j++){
                file >> matrix_2.matrix_data[i][j];
            }
        }
        file.close();
        }
}





void print_matrix(const Matrix& matrix){
    // TODO: Print the matrix to the console
    for(int i = 0; i<matrix.matrix_size; i++){
        for(int j = 0; j<matrix.matrix_size; j++){
            cout << matrix.matrix_data[i][j] << " ";
        }
        cout << endl;
    }
}
void print_matrix(const Matrix& matrix_1, const Matrix& matrix_2) {
    // TODO: Print both matrices to the console
    for(int i = 0; i<matrix_1.matrix_size; i++){
        for(int j = 0; j<matrix_1.matrix_size; j++){
            cout << matrix_1.matrix_data[i][j] << " ";
        }
        cout << " ";
        for(int j = 0; j<matrix_2.matrix_size; j++){
            cout << matrix_2.matrix_data[i][j] << " ";
        }
        cout << endl;
    }
}
Matrix add_matrices(const Matrix& matrix_1, const Matrix& matrix_2) {
    // TODO: Implement matrix addition
    for(int i=0; i<matrix_1.matrix_size; i++){
        for(int j=0; j<matrix_1.matrix_size; j++){
            matrix_1.matrix_data[i][j] += matrix_2.matrix_data[i][j];
        }
    }
    return matrix_1;
}
Matrix multiply_matrices(const Matrix& matrix_1, const Matrix& matrix_2){
    // TODO: Implement matrix multiplication
    for(int i=0; i<matrix_1.matrix_size; i++){
        for(int j=0; j<matrix_1.matrix_size; j++){
            matrix_1.matrix_data[i][j] *= matrix_2.matrix_data[j][i];
        }
    }
    return matrix_1;
}

// Overloaded + operator for matrix addition
Matrix operator +(const Matrix& matrix_1, const Matrix& matrix_2);

// Overloaded * operator for matrix multiplication
Matrix operator *(const Matrix& matrix_1, const Matrix& matrix_2);
void get_diagonal_sum(const Matrix& matrix) {
    // TODO: Calculate and print the sum of the diagonal elements
    int sum = 0;
    for (int i = 0; i < matrix.matrix_size; i++) {
        sum += matrix.matrix_data[i][i];
    }
    cout << sum << endl;
}


void swap_matrix_row(Matrix& matrix, int row1, int row2) {
    // TODO: Swap the rows 'row1' and 'row2' in the matrix
    //    Handle invalid row indices
    double* temp = matrix.matrix_data[row1];
    matrix.matrix_data[row1] = matrix.matrix_data[row2];
    matrix.matrix_data[row2] = temp;
    print_matrix(matrix);

}
int main(int argc, char* argv[]) {
    Matrix matrix_1, matrix_2;
    read_matrix_from_file("matrix.txt", matrix_1, matrix_2);

    cout << "print_matrix" << endl;
    print_matrix(matrix_1, matrix_2);

    cout << "add_matrices result:" << endl;
    Matrix add_result_1 = add_matrices(matrix_1, matrix_2);
    Matrix add_result_2 = matrix_1 + matrix_2;
    print_matrix(add_result_1);
    print_matrix(add_result_2);

    cout << "multiply_matrices result:" << endl;
    Matrix multiply_result_1 = multiply_matrices(matrix_1, matrix_2);
    Matrix multiply_result_2 = matrix_1 * matrix_2;
    print_matrix(multiply_result_1);
    print_matrix(multiply_result_2);

    cout << "get matrix diagonal sum" << endl;
    get_diagonal_sum(matrix_1);

    cout << "swap matrix rows" << endl;
    swap_matrix_row(matrix_1, 0, 1);

    return 0;
}
