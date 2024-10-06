// Cplus_For_Self_Driving_Car.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Library for basic function using C++
#include <iostream>
#include <vector>
#include "Matrix.h"

using namespace std;

//// Basic Function Group: (Base 1)
//void print(vector<float> vector1);
//void print(vector<vector<int>> vector1); // print 2 dimension int vector
//vector<float> vectorMultiplication(vector<float> vector1, vector<float> vector2);
//vector<vector<int>> vectorMultiplication(vector<vector<int>> vector1, vector<vector<int>> vector2);
//
//// Localization Function Group:
//vector<float> sense(vector<float> p, vector<string> world, string Z, float pHit, float pMiss);
//vector<float> move(vector<float> p, vector<string> world, int U, float pExact, float pOvershoot, float pUndershoot);
//void print_probability(vector<double> p);
//
//// Gausian class test


int main()
{
    vector <vector <float> >
        initial_grid(7, vector <float>(5, 0.4));

    Matrix matrixa(initial_grid);

    matrixa.matrix_print();

}

//int main()
//{
//    // std::cout << "Hello World!\n";
//    /************************************Test 1********************************************/
//    //vector<float> v1(3); //v1[0] = 5.0; v1[1] = 10.0; v1[2] = 27.0;
//    //vector<float> v2(3); //v2[0] = 2.0; v2[1] = 17.0; v2[2] = 12.0;
//    //vector<float> v3(v1.size()); //v3 = vectorMultiplication(v1, v2); //print(v3);
//
//    /************************************Test 2********************************************/  
//    //vector < vector <int> > matrix1(5, vector <int>(3, 2));
//    //vector < vector <int> > matrix2(5, vector <int>(3, 26));
//    //print(matrix1);
//    //vector < vector<int> > matrix3;
//    //matrix3 = vectorMultiplication(matrix1, matrix2);
//    //print(matrix3);
//     /************************************Test 3********************************************/
//    vector<float> p = { 0.2, 0.2, 0.2, 0.2, 0.2 };
//    vector<string> world = { "green", "red", "red", "green", "green" };
//    vector<string> measurement = { "red", "green" };
//    vector<int> motions = { 1, 1 };
//    float pHit = 0.6;
//    float pMiss = 0.2;
//    float pExact = 0.8;
//    float pOvershoot = 0.1;
//    float pUndershoot = 0.1;
//
//}
//
//vector<float> sense(vector<float> p, vector<string> world, string Z, float pHit, float pMiss) {
//    /*
//     * Updates probability based on a sensor reading.
//     */
//    vector<float> sense(p.size());
//    bool hit;
//    double s = 0; // sum of the q vector's elements
//
//    for (int i = 0; i < p.size(); i++) {
//        hit = (Z == world[i]);
//        sense.push_back(p[i] * (hit * pHit + (1 - hit) * pMiss));
//        s += sense[i];
//    }
//    // Divide probabilities by the total sum
//    for (int i = 0; i < sense.size(); i++) {
//        sense[i] = sense[i] / s;
//    }
//    return sense;
//}
//
//vector<float> move(vector<float> p, vector<string> world, int U, 
//    float pExact, float pOvershoot, float pUndershoot) {
//    vector<float> move(p.size());
//    double s = 0; //
//
//    for (int i = 0; i < p.size(); i++) {
//        if (i - U < 0) {
//            s = pExact * p[(i - U) + p.size()];
//        }
//        else {
//            s = pExact * p[(i - U) % p.size()];
//        }
//        if (i - U - 1 < 0) {
//            s = s + pOvershoot * p[(i - U - 1) + p.size()];
//        }
//        else {
//            s = s + pOvershoot * p[(i - U - 1) % p.size()];
//        }
//        if (i - U + 1 < 0) {
//            s = s + pUndershoot * p[(i - U + 1) + p.size()];
//        }
//        else {
//            s = s + pUndershoot * p[(i - U + 1) % p.size()];
//        }
//        move[i] = s;
//    }
//
//    return move;
//}
//
//void print_probability(vector<double> p) {
//    // Iterates through the vector to print it out
//    for (int i = 0; i < p.size(); i++) {
//        cout << p[i] << " ";
//    }
//    cout << endl;
//}
//// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
//// Debug program: F5 or Debug > Start Debugging menu
//
//// Tips for Getting Started: 
////   1. Use the Solution Explorer window to add/manage files
////   2. Use the Team Explorer window to connect to source control
////   3. Use the Output window to see build output and other messages
////   4. Use the Error List window to view errors
////   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
////   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
//
//    /************************************Test 1********************************************/
//// Vector multiplication function!
//vector<float> vectorMultiplication(vector<float> vector1, vector<float> vector2)
//{
//    if (vector1.size() == vector2.size()){
//        vector<float> result(vector1.size());
//        for (int i = 0; i < vector1.size(); i++) {
//            result[i] = vector1[i] * vector2[i];
//        }
//        return result;
//    }
//    else {
//        cout << "Vector size is not equal!\n";
//    }
//    return vector<float>();
//}
//
////2 dimensional multiplication.
//vector<vector<int>> vectorMultiplication(vector<vector<int>> matrix1, vector<vector<int>> matrix2)
//{
//    if (matrix1.size() == matrix2.size() && matrix1[0].size() == matrix2[0].size()) {
//        vector<vector<int>> result(matrix1.size(), vector <int>(matrix1[0].size(), 0));
//        for (int i = 0; i < matrix1.size(); i++) {
//            for (int j = 0; j < matrix1[i].size(); j++)
//            {
//                result[i][j] = matrix1[i][j] * matrix2[i][j];
//            }
//        }
//        return result;
//    }
//    else {
//        cout << "Vector size is not equal!\n";
//    }
//    return vector<vector<int>>();
//}
//
////print 1 dimension vector.
//void print(vector<float> vector1) {
//    for (int i = 0; i < vector1.size(); ++i) {
//        if (i % 5 == 0) {
//            cout << "\n";
//        }
//        cout << vector1[i]<<" ";
//    }
//}
//
////print 2 dimensional vector.
//void print(vector<vector<int>> vector1) {
//    for (int i = 0; i < vector1.size(); ++i) {
//        for (int j = 0; j < vector1[i].size(); ++j) {
//            cout << vector1[i][j] << " "; 
//        }
//        cout << "\n";
//    }
//}
///************************************Test 2********************************************/