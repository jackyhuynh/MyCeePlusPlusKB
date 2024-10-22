//
// Created by truc huynh on 10/21/24.
//
#include <iostream>

class Outer {

private:
  int privateNumber =1;

  protected:
    int protectedNumber =2;
    int getPrivateNumber() const{
      return privateNumber;
    }

  public:
      // Function in the outer class
      void display() const {
          std::cout << "Outer class display()" << std::endl;
      }

      void displayPrivate() const {
        std::cout << "Outer class displayPrivate() " << privateNumber<< std::endl;
      }

      void displayProtected() const {
        std::cout << "Outer class displayProtected()" << protectedNumber << std::endl;
      }

      int getPrivateNumberPublic() const{
        return privateNumber;
      }


       class Inner {
       public:
           // Function in the inner class with the same signature
           void display() const {
               std::cout << "Inner class display()" << std::endl;
           }
       };
};

class ChildOuter : public Outer {
  public:
    void display() const {
        std::cout << "Child class display()" << std::endl;
    }

    void displayPrivateProtected() const {
        int Number= this->getPrivateNumber();
        std::cout << "Outer class displayPrivate() " << Number << std::endl;
    }

    void displayPrivate() const {
      std::cout << "Outer class displayPrivate() " << privateNumber<< std::endl;
    }

    void displayProtected() const {
      std::cout << "Outer class displayProtected()" << protectedNumber << std::endl;
    }

};

int main() {
    Outer outer;

    // Calls the outer class's display()
    outer.display();
    outer.displayPrivate();
    outer.displayProtected();

    ChildOuter childOuter;
    childOuter.display();
    childOuter.displayPrivate();
    childOuter.displayProtected();
    childOuter.displayPrivateProtected();   

    return 0;
}