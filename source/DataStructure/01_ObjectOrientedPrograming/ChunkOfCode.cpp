#include <iostream>

using namespace std;


int sum(int inputsQuantity)
{
    int input = 0;
    int sum = 0;

    for (int i = 0; i < inputsQuantity; i++)
    {
        cout << "Type a number: ";
        cin >> input;
        sum = sum + input;
    }

    return sum;
}

int getUserinput(){
    int input = 0;
    cout << endl<< "Type a number:";
    cin >> input;
    return input;
}


int main()
{
    int sum = 0;

    for (int i=0; i<3; i++ ){
        sum += getUserinput();
    }

    cout << "sum is: " <<sum;
    return 0;
}