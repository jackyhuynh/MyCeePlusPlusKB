#include <iostream>

using namespace std;
/**
 * Regular String Array C++
 */

int main()
{
    string cars[]={"Covette", "Camry", "Camero"};
    cout << "This is the car array: " << *cars << endl;
    cout << "This is the car array: " << cars << endl;

    for (int i = 0; i<3; i++)
    {
        cout << cars[i] << endl;
    }

    // This is another way to access without for
    // cout << cars[3] << endl;
    cout << cars[2] << endl;

    bool index = true;

    while (index){
        cout << "It is always true" << endl;
        index = false;
        cout << "It is not always true anymore" << endl; 
    }
}