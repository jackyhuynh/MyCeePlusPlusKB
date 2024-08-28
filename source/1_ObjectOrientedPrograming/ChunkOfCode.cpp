#include <iostream>

using namespace std;

void print_anything(int input){
    cout << to_string(input);
}

int main()
{
    int input=0;
    cout << "hello world" << endl;
    cout << "Type a number:";
    cin >> input;

    print_anything(input);
    return 0;
}