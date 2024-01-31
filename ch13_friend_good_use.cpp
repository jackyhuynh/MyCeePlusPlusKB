#include <iostream>
/*
    Definition: A good use of friend is when it is necessary for two or more classes to interact closely 
    with each other's internal states in a way that cannot be accomplished through public 
    interfaces without exposing internal details more broadly than desired. 
    
    Use case: An example of a good use case is the implementation of operator overloading that requires 
    access to private data, 
        - Like the operator<< for output stream operations.
        - In this case, friend is used judiciously to allow the operator<< function to access the 
        private data of SecretData for printing, without making the internal data public, 
        which would violate encapsulation.

*/
class SecretData {
    int secretValue;

public:
    SecretData(int value) : secretValue(value) {}

    // Declare a non-member function as a friend so it can access private members.
    friend std::ostream& operator<<(std::ostream& os, const SecretData& obj);
};

// Implementation of the friend function.
std::ostream& operator<<(std::ostream& os, const SecretData& obj) {
    os << "Secret Value: " << obj.secretValue;
    return os;
}

int main() {
    SecretData myData(42);
    std::cout << myData << std::endl; // Now we can directly print SecretData objects.
    return 0;
}
