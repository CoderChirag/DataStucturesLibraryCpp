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


// ---------------- UpperTriangular Matrix -------------------------------
// Constructors
UpperTriangularMatrix::UpperTriangularMatrix(int n, const int* rowMajorElements){
    this->m = n;
    this->n = n;
    arr = new int[(n*(n+1))/2];
    for (int i = 0; i < (n*(n+1))/2; i++){
        arr[i] = rowMajorElements[i];
    }
}
UpperTriangularMatrix::UpperTriangularMatrix(const UpperTriangularMatrix& mat){
    this->m = mat.getRows();
    this->n = mat.getCols();
    arr = mat.getRepresentation();
}

// Accessors
int** UpperTriangularMatrix::get() const{
    int **mat = new int*[n];
    int k = 0;
    for (int i = 0; i<n; i++){
        int *row = new int[n]{0};
        mat[i] = row;
        for (int j = 0; j < n; j++){
            if(i <= j){
                row[j] = arr[k];
                k++;
            }
        }
    }
    return mat;
}
int* UpperTriangularMatrix::getRepresentation() const{
    int* arr = new int[(n*(n+1))/2];
    for (int i = 0; i < (n*(n+1))/2; i++){
        arr[i] = this->arr[i];
    }
    return arr;
}
int UpperTriangularMatrix::at(int i, int j) const{
    if(i < m && j < n && i >= 0 && j >= 0){
        if(i <= j){
            return arr[(i*n - (i*(i-1))/2) + (j-i)];
        }
        return 0;
    }

    throw std::runtime_error(std::string("Array index out of bound exception"));
}

// Mutators
void UpperTriangularMatrix::set(int i, int j, int num){
    if(i < m && j < n && i >= 0 && j >= 0){
        if(i <= j){
            arr[(i*n - (i*(i-1))/2) + (j-i)] = num;
        }
        return;
    }
    throw std::runtime_error(std::string("Array index out of bound exception"));
}

// Destructors
UpperTriangularMatrix::~UpperTriangularMatrix(){
    delete[] arr;
}

// ------------------------ Sparse Matrix ------------------------
SparseElement::SparseElement() : i{-1}, j{-1}, x{0}{}
// Constructors
SparseMatrix::SparseMatrix(int m, int n): num{0}, size{0}{
    this->m = m;
    this->n = n;
    ele = new SparseElement[this->num];
}
SparseMatrix::SparseMatrix(SparseMatrix& mat){
    m = mat.getRows();
    n = mat.getCols();
    num = mat.getSparseArrayLength();
    size = mat.getSize();
    ele = mat.getSparseElements();
}

// Accessors (Getter Functions)
int SparseMatrix::getSparseArrayLength() const{
    return num;
}
int SparseMatrix::getSize() const{
    return size;
}
SparseElement* SparseMatrix::getSparseElements() const{
    SparseElement *ele = new SparseElement[num];
    for (int i = 0; i < num; i++){
        ele[i] = this->ele[i];
    }
    return ele;
}
int SparseMatrix::getSparseIndex(int i, int j) const{
    if(i < m && j < n && i >=0 && j >= 0){
        int l = 0;
        int r = num - 1;
        while(l<=r){
            int mid = (l + r) / 2;
            if(ele[mid].i == i){
                if(ele[mid].j == j){
                    return mid;
                }else if(ele[mid].j < j){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }else if(ele[mid].i < i){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return -1;
    }

    throw std::runtime_error(std::string("Array index out of bound exception "));
}
int** SparseMatrix::get() const{
    int **mat = new int *[m];
    for (int i = 0; i < m; i++){
        int *row = new int[n]{0};
        mat[i] = row;
    }
    for (int i = 0; i < num; i++){
        if(!ele[i].i == -1 && !ele[i].j == -1){
            mat[ele[i].i][ele[i].j] = ele[i].x;
        }
    }
    return mat;
}
int SparseMatrix::at(int i, int j) const{
    if(i < m && j < n && i >=0 && j >= 0){
        int l = 0;
        int r = num - 1;
        while(l<=r){
            int mid = (l + r) / 2;
            if(ele[mid].i == i){
                if(ele[mid].j == j){
                    return ele[mid].x;
                }else if(ele[mid].j < j){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }else if(ele[mid].i < i){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return 0;
    }

    throw std::runtime_error(std::string("Array index out of bound exception "));
}

// Mutators (Setter Functions)
void SparseMatrix::set(int i, int j, int x){
    if(i < m && j < n && i >=0 && j >= 0){
        int index = getSparseIndex(i, j);
        if(x == 0){
            if( index != -1){
                for (int k = index; k < num-1; k++){
                    ele[k] = ele[k + 1];
                }
                ele[num - 1].i = -1;
                ele[num - 1].j = -1;
                ele[num - 1].x = 0;
                num--;
            }
        }else{
            if(index != -1){
                ele[index].x = x;
            }else{
                SparseElement *ele = new SparseElement[num + 1];
                bool flag = false;

                if(num == 0){
                    ele[0].i = i;
                    ele[0].j = j;
                    ele[0].x = x;
                    flag = true;
                }else{
                    int k = 0;
                    while(k<num && this->ele[k].i < i){
                        ele[k] = this->ele[k];
                        k++;
                    }
                    if(k<num && this->ele[k].i == i){
                        while(k<num && this->ele[k].j < j){
                            ele[k] = this->ele[k];
                            k++;
                        }
                        if(k<num && this->ele[k].j > j){
                            ele[k].i = i;
                            ele[k].j = j;
                            ele[k].x = x;
                            flag = true;
                            k++;
                        }

                    }else if(k < num){
                        ele[k].i = i;
                        ele[k].j = j;
                        ele[k].x = x;
                        flag = true;
                        k++;
                    }

                    
                    if(flag){
                        while(k<num+1){
                            ele[k] = this->ele[k - 1];
                            k++;
                        }
                    }else{
                        ele[num].i = i;
                        ele[num].j = j;
                        ele[num].x = x;
                        flag = true;
                    }

                }

                num++;
                delete[] this->ele;
                this->ele = ele;
            }
        }
        return;
    }

    throw std::runtime_error(std::string("Array index out of bound exception "));
}

//  Facilitators
SparseMatrix* SparseMatrix::add(const SparseMatrix& s) const{
    if(m!=s.m || n!=s.n)
        throw std::runtime_error(std::string("Only thee matrices having same rows and columns can be added"));

    SparseMatrix *sum = new SparseMatrix{m, n};
    delete[] sum->ele;
    SparseElement *ele = new SparseElement[num + s.num];
    sum->ele = ele;
    sum->size = num + s.num;
    int i = 0, j = 0, k = 0;
    while(i < num && j < s.num){
        if(this->ele[i].i < s.ele[j].i){
            sum->ele[k++] = this->ele[i++];
        }else if(this->ele[i].i > s.ele[j].i){
            sum->ele[k++] = s.ele[j++];
        }else{
            if(this->ele[i].j < s.ele[j].j){
                sum->ele[k++] = this->ele[i++];
            }else if(this->ele[i].j > s.ele[j].j){
                sum->ele[k++] = s.ele[j++];
            }else{
                sum->ele[k] = this->ele[i++];
                sum->ele[k++].x += s.ele[j++].x;
            }
        }
    }
    while(i < num){
        sum->ele[k++] = this->ele[i++];
    }
    while(j < s.num){
        sum->ele[k++] = s.ele[j++];
    }
    sum->num = k;

    return sum;
}

// Operator Overloads
SparseMatrix& SparseMatrix::operator+(SparseMatrix &s){
    if(m!=s.m || n!=s.n)
        throw std::runtime_error(std::string("Only thee matrices having same rows and columns can be added"));

    SparseMatrix *sum = new SparseMatrix{m, n};
    delete[] sum->ele;
    SparseElement *ele = new SparseElement[num + s.num];
    sum->ele = ele;
    sum->size = num + s.num;
    int i = 0, j = 0, k = 0;
    while(i < num && j < s.num){
        if(this->ele[i].i < s.ele[j].i){
            sum->ele[k++] = this->ele[i++];
        }else if(this->ele[i].i > s.ele[j].i){
            sum->ele[k++] = s.ele[j++];
        }else{
            if(this->ele[i].j < s.ele[j].j){
                sum->ele[k++] = this->ele[i++];
            }else if(this->ele[i].j > s.ele[j].j){
                sum->ele[k++] = s.ele[j++];
            }else{
                sum->ele[k] = this->ele[i++];
                sum->ele[k++].x += s.ele[j++].x;
            }
        }
    }
    while(i < num){
        sum->ele[k++] = this->ele[i++];
    }
    while(j < s.num){
        sum->ele[k++] = s.ele[j++];
    }
    sum->num = k;

    return *sum;
}

// Destructor
SparseMatrix::~SparseMatrix(){
    delete[] ele;
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
std::ostream &operator<<(std::ostream &cout, const UpperTriangularMatrix &mat){
    int k = 0;
    for (int i = 0; i < mat.m; i++){
        for (int j = 0; j < mat.n; j++){
            if(i <= j){
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
std::ostream& operator<<(std::ostream& cout, SparseMatrix& mat){
    for (int i = 0; i < mat.m; i++){
        for (int j = 0; j < mat.n; j++){
            int index = mat.getSparseIndex(i, j);
            if(index == -1){
                cout << "0 ";
            }else{
                cout << mat.ele[index].x << " ";
            }
        }
        cout << std::endl;
    }
    return cout;
}