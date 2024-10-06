#ifndef GAUSSIAN_H
#define GAUSSIAN_H
//
// The solution is to use # ifndef statements, which allow you to 
// implement a technique called inclusion guards.
//
// The ifndef statement stands for "if not defined".When you wrap your 
// header files with #ifndef statements, the compiler will only include 
// a header file if the file has not yet been defined.
//

class Gaussian
{
private:
    float mu, sigma2;

public:

    // constructor functions
    Gaussian();
    Gaussian(float, float);

    // changes value of average and standard deviation 
    void setMu(float);
    void setSigma2(float);

    // outputs value of average and standard deviation
    float getMu();
    float getSigma2();

    // class methods
    float evaluate(float);
    Gaussian mul(Gaussian);
    Gaussian add(Gaussian);
};

#endif /* GAUSSIAN_H */