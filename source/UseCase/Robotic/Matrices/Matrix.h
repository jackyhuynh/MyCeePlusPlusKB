#ifndef MATRIX_H
#define MATRIX_H

// The solution is to use # ifndef statements, which allow you to 
// implement a technique called inclusion guards.
//
// The ifndef statement stands for "if not defined".When you wrap your 
// header files with #ifndef statements, the compiler will only include 
// a header file if the file has not yet been defined.
//

class Matrix
{
private:
    std::vector< std::vector<float> > grid;
    std::vector<float>::size_type rows;
    std::vector<float>::size_type cols;

    /*The value that goes inside the brackets
    <> is based on whatever the original vector
    declaration was.A size_type variable is actually
    an unsigned int.The size_type variable is
    guaranteed to be able to hold up to the maximum
    size of a float vector.*/

public:

    // constructor functions
    Matrix();
    Matrix(std::vector< std::vector<float> >);

    // set functions
    void setGrid(std::vector< std::vector<float> >);

    // get functions
    std::vector< std::vector<float> > getGrid();
    std::vector<float>::size_type getRows();
    std::vector<float>::size_type getCols();

    // matrix functions
    Matrix matrix_transpose();
    Matrix matrix_addition(Matrix);

    // matrix printing
    void matrix_print();
};


#endif