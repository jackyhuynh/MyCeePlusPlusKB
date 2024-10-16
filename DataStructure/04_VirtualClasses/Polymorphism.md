# Polymorphism

Polymorphism is a key concept in object-oriented programming (OOP) that allows objects of different classes to be
treated as objects of a common superclass. It enables a single interface to be used for different underlying forms (data
types). In simpler terms, polymorphism allows the same operation or method to behave differently based on the object it
is acting upon.

There are two main types of polymorphism:

1. **Compile-time polymorphism (Static polymorphism)**:
    - This is achieved through **method overloading** or **operator overloading**.
    - In method overloading, multiple methods share the same name but differ in the type or number of parameters.
    - Example in Java:Polymorphism
      ```java
      class MathOperation {
          public int add(int a, int b) {
              return a + b;
          }Polymorphism
          public double add(double a, double b) {
              return a + b;
          }
      }
      ```
      Here, the `add` method is overloaded to handle both integer and double types.

2. **Run-time polymorphism (Dynamic polymorphism)**:
    - This is achieved through **method overriding**, where a subclass provides a specific implementation of a method
      already defined in its superclass.
    - Example in Java:
      ```java
      class Animal {
          public void sound() {
              System.out.println("Animal makes a sound");
          }
      }
      class Dog extends Animal {
          @Override
          public void sound() {
              System.out.println("Dog barks");
          }
      }
      class Cat extends Animal {
          @Override
          public void sound() {
              System.out.println("Cat meows");
          }
      }
      public class Main {
          public static void main(String[] args) {
              Animal myDog = new Dog();
              Animal myCat = new Cat();
              myDog.sound();  // Outputs: Dog barks
              myCat.sound();  // Outputs: Cat meows
          }
      }
      ```
      In this example, both `Dog` and `Cat` override the `sound()` method from the `Animal` class, and the appropriate
      version is called at runtime based on the actual object.

**Polymorphism** allows for flexibility and reusability of code, making it easier to manage and scale.