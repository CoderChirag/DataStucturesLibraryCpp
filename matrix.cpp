#include<iostream>
#include<stdexcept>
#include"matrix.h"

// -------------- Matrix ----------------------------------
int Matrix::getRows() const{
    return m;
}
int Matrix::getCols() const {
    return n;
}


// ----------- Matrixx ---------------------------------
// Constructors
Matrixx::Matrixx(int m, int n){
    this->m = m;
    this->n = n;
    mat = new int*[m];
    for (int i = 0; i < m; i++){
        mat[i] = new int[n]{0};
    }
}
Matrixx::Matrixx(int m, int n, const void* matrix){
    this->m = m;
    this->n = n;
    int** mat = (int **)matrix;
    this->mat = new int *[m];
    for (int i = 0; i < m; i++){
        int *col = new int[n];
        this->mat[i] = col;
        for (int j = 0; j < n; j++){
            this->mat[i][j] = mat[i][j];
        }
    }
}
Matrixx::Matrixx(const Matrixx &mat){ // Copy Constructor
    m = mat.getRows();
    n = mat.getCols();
    this->mat = new int *[m];
    for (int i = 0; i < m; i++){
        int *row = new int[n];
        this->mat[i] = row;
        for (int j = 0; j < n; j++){
            this->mat[i][j] = mat.at(i, j);
        }
    }
}

// Accessors (Getter Functions)
int** Matrixx::get() const{
    int **mat = new int *[m];
    for (int i = 0; i < m; i++){
        int *row = new int[n];
        mat[i] = row;
        for (int j = 0; j < n; j++){
            row[j] = this->mat[i][j];
        }
    }
    return mat;
}
int Matrixx::at(int i, int j) const{
    if(i < m && j < n && i >= 0 && j >= 0){
        return mat[i][j];
    }

    throw std::runtime_error(std::string("Array index out of bound exception"));
}

// Mutators (Setter Functions)
void Matrixx::set(int i, int j, int num){
    if(i < m && j < n && i >= 0 && j >= 0){
        mat[i][j] = num;
        return;
    }

    throw std::runtime_error(std::string("Array index out of bound exception"));
}

// Destructors
Matrixx::~Matrixx(){
    for (int i = 0; i < m; i++){
        delete[] mat[i];
    }

    delete[] mat;
}


// ---------------- Diagonal Matrix -------------------------------
// Constructors
DiagonalMatrix::DiagonalMatrix(int n, const int* diagonalElements){
    this->m = n;
    this->n = n;
    arr = new int[m];
    for (int i = 0; i < m; i++){
        arr[i] = diagonalElements[i];
    }
}
DiagonalMatrix::DiagonalMatrix(const DiagonalMatrix& mat){
    this->m = mat.getRows();
    this->n = mat.getCols();
    arr = new int[m];
    for (int i = 0; i < n; i++){
        arr[i] = mat.at(i, i);
    }
}

// Accessors
int** DiagonalMatrix::get() const{
    int** mat = new int*[m];
    for (int i = 0; i < m; i++){
        int* row = new int[n]{0};
        row[i] = arr[i];
        mat[i] = row;
    }
    return mat;
}
int DiagonalMatrix::at(int i, int j) const{
    if(i < m && j < n && i >= 0 && j >= 0){
        if(i == j){
            return arr[i];
        }
        return 0;
    }

    throw std::runtime_error(std::string("Array index out of bound exception"));
}

// Mutators
void DiagonalMatrix::set(int i, int j, int num){
    if(i < m && j < n && i >= 0 && j >= 0){
        if(i == j){
            arr[i] = num;
        }
        return;
    }
    throw std::runtime_error(std::string("Array index out of bound exception"));
}

// Destructors
DiagonalMatrix::~DiagonalMatrix(){
    delete[] arr;
}

// ---------------- LowerTriangular Matrix -------------------------------
// Constructors
LowerTriangularMatrix::LowerTriangularMatrix(int n, const int* rowMajorElements){
    this->m = n;
    this->n = n;
    arr = new int[(n*(n+1))/2];
    for (int i = 0; i < (n*(n+1))/2; i++){
        arr[i] = rowMajorElements[i];
    }
}
LowerTriangularMatrix::LowerTriangularMatrix(const LowerTriangularMatrix& mat){
    this->m = mat.getRows();
    this->n = mat.getCols();
    arr = mat.getRepresentation();
}

// Accessors
int** LowerTriangularMatrix::get() const{
    int **mat = new int*[n];
    int k = 0;
    for (int i = 0; i<n; i++){
        int *row = new int[n]{0};
        mat[i] = row;
        for (int j = 0; j < n; j++){
            if(i >=j){
                row[j] = arr[k];
                k++;
            }
        }
    }
    return mat;
}
int* LowerTriangularMatrix::getRepresentation() const{
    int* arr = new int[(n*(n+1))/2];
    for (int i = 0; i < (n*(n+1))/2; i++){
        arr[i] = this->arr[i];
    }
    return arr;
}
int LowerTriangularMatrix::at(int i, int j) const{
    if(i < m && j < n && i >= 0 && j >= 0){
        if(i >= j){
            return arr[(i*(i+1))/2 + j];
        }
        return 0;
    }

    throw std::runtime_error(std::string("Array index out of bound exception"));
}

// Mutators
void LowerTriangularMatrix::set(int i, int j, int num){
    if(i < m && j < n && i >= 0 && j >= 0){
        if(i >= j){
            arr[(i*(i+1))/2 + j] = num;
        }
        return;
    }
    throw std::runtime_error(std::string("Array index out of bound exception"));
}

// Destructors
LowerTriangularMatrix::~LowerTriangularMatrix(){
    delete[] arr;
}



// Operator Overloads
std::ostream &operator<<(std::ostream& cout, const Matrixx& mat){
    for (int i = 0; i < mat.m; i++){
        for (int j = 0; j < mat.n; j++){
            if(j != mat.getCols()-1){
                cout << mat.mat[i][j] << " ";
            }else{
                cout << mat.mat[i][j] << std::endl;
            }
        }
    }
    return cout;
}
std::ostream &operator<<(std::ostream &cout, const DiagonalMatrix &mat){
    for (int i = 0; i < mat.m; i++){
        for (int j = 0; j < mat.n; j++){
            if(i == j){
                if(j != mat.n-1){
                    cout << mat.arr[i] << " ";
                }else{
                    cout << mat.arr[i] << std::endl;
                }
            }else{
                if(j != mat.n-1){
                    cout << "0 ";
                }else{
                    cout << "0" << std::endl;
                }
            }
        }
    }

    return cout;
}
std::ostream &operator<<(std::ostream &cout, const LowerTriangularMatrix &mat){
    int k = 0;
    for (int i = 0; i < mat.m; i++){
        for (int j = 0; j < mat.n; j++){
            if(i >= j){
                cout << mat.arr[k] << " ";
                k++;
            }else{
                cout << "0 ";
            }
        }
        cout << std::endl;
    }

    return cout;
}