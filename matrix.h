#ifndef MATRIX_H
#define MATRIX_H
class Matrix{
    protected:
        int m, n;
    public:
        // Accessors (Getter Functions)
        virtual int at(int i, int j) const = 0;
        virtual int **get() const = 0;
        int getRows() const;
        int getCols() const;

        // Mutators (Setter Functions)
        virtual void set(int i, int j, int num) = 0;

        // // Facilitators
        // virtual int *add(Matrix &mat) const = 0;
        // virtual int *subtract(Matrix &mat) const = 0;
        // virtual int *subtractFrom(Matrix &mat) const = 0;
        // virtual int *multiplyWith(Matrix &mat) const = 0;
        // virtual int *multiplyTo(Matrix &mat) const = 0;
};

class Matrixx : public Matrix{
    private:
        int **mat;
    public:
        // Constructors
        Matrixx(int m, int n);
        Matrixx(int m, int n, const void* matrix);
        Matrixx(const Matrixx &mat); // Copy Constructor

        // Accessors (Getter Functions)
        int** get() const;
        int at(int i, int j) const;

        // Mutators (Setter Functions)
        void set(int i, int j, int num);

        // Facilitators
        // int *add(Matrix &mat);
        // int *subtract(Matrix &mat);
        // int *subtractFrom(Matrix &mat);
        // int *multiplyWith(Matrix &mat);
        // int *multiplyTo(Matrix &mat);

        // Operator Overloads
        friend std::ostream &operator<<(std::ostream &cout, const Matrixx &mat);

        // Destructors
        ~Matrixx();

};

class DiagonalMatrix : public Matrix{
    private:
        int *arr;
    public:
        // Constructors
        DiagonalMatrix(int n, const int *digonalElements);
        DiagonalMatrix(const DiagonalMatrix &mat);

        // Accessors (Getter Functions)
        int** get() const;
        int at(int i, int j) const;

        // Mutators (Setter Functions)
        void set(int i, int j, int num);

        // Facilitators
        // int *add(Matrix &mat);
        // int *subtract(Matrix &mat);
        // int *subtractFrom(Matrix &mat);
        // int *multiplyWith(Matrix &mat);
        // int *multiplyTo(Matrix &mat);

        // Operator Overloads
        friend std::ostream &operator<<(std::ostream &cout, const DiagonalMatrix &mat);

        // Destructors
        ~DiagonalMatrix();
};

class LowerTriangularMatrix : public Matrix{
    private:
        int *arr;
    public:
        // Constructors
        LowerTriangularMatrix(int n, const int *rowMajorElements);
        LowerTriangularMatrix(const LowerTriangularMatrix &mat);

        // Accessors (Getter Functions)
        int** get() const;
        int *getRepresentation() const;
        int at(int i, int j) const;

        // Mutators (Setter Functions)
        void set(int i, int j, int num);

        // Facilitators
        // int *add(Matrix &mat);
        // int *subtract(Matrix &mat);
        // int *subtractFrom(Matrix &mat);
        // int *multiplyWith(Matrix &mat);
        // int *multiplyTo(Matrix &mat);

        // Operator Overloads
        friend std::ostream &operator<<(std::ostream &cout, const LowerTriangularMatrix &mat);

        // Destructors
        ~LowerTriangularMatrix();
};

class UpperTriangularMatrix : public Matrix{
    private:
        int *arr;
    public:
        // Constructors
        UpperTriangularMatrix(int n, const int *rowMajorElements);
        UpperTriangularMatrix(const UpperTriangularMatrix &mat);

        // Accessors (Getter Functions)
        int** get() const;
        int *getRepresentation() const;
        int at(int i, int j) const;

        // Mutators (Setter Functions)
        void set(int i, int j, int num);

        // Facilitators
        // int *add(Matrix &mat);
        // int *subtract(Matrix &mat);
        // int *subtractFrom(Matrix &mat);
        // int *multiplyWith(Matrix &mat);
        // int *multiplyTo(Matrix &mat);

        // Operator Overloads
        friend std::ostream &operator<<(std::ostream &cout, const UpperTriangularMatrix &mat);

        // Destructors
        ~UpperTriangularMatrix();
};
#endif