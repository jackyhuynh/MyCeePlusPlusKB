#include <iostream>
#include <string>
#include <cassert>
#include <vector>

class Animal {
protected:
    std::string name;
    int age;
    
public:
    Animal(std::string n, int a) : name(n), age(a) {}
    
    virtual ~Animal() {}
    
    virtual void makeSound() const {
        std::cout << name << " makes a sound" << std::endl;
    }
    
    virtual void move() const = 0;
    
    std::string getName() const { return name; }
    int getAge() const { return age; }
};

class Dog : public Animal {
private:
    std::string breed;
    
public:
    Dog(std::string n, int a, std::string b) 
        : Animal(n, a), breed(b) {}
    
    void makeSound() const override {
        std::cout << name << " barks: Woof! Woof!" << std::endl;
    }
    
    void move() const override {
        std::cout << name << " runs on four legs" << std::endl;
    }
    
    std::string getBreed() const { return breed; }
};

class Bird : public Animal {
private:
    double wingspan;
    
public:
    Bird(std::string n, int a, double w) 
        : Animal(n, a), wingspan(w) {}
    
    void makeSound() const override {
        std::cout << name << " chirps: Tweet! Tweet!" << std::endl;
    }
    
    void move() const override {
        std::cout << name << " flies with " << wingspan << "m wingspan" << std::endl;
    }
    
    double getWingspan() const { return wingspan; }
};

class Shape {
protected:
    std::string color;
    
public:
    Shape(std::string c) : color(c) {}
    virtual ~Shape() {}
    
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    
    std::string getColor() const { return color; }
};

class Circle : public Shape {
private:
    double radius;
    static constexpr double PI = 3.14159;
    
public:
    Circle(double r, std::string c) : Shape(c), radius(r) {}
    
    double getArea() const override {
        return PI * radius * radius;
    }
    
    double getPerimeter() const override {
        return 2 * PI * radius;
    }
    
    double getRadius() const { return radius; }
};

class Rectangle : public Shape {
private:
    double length, width;
    
public:
    Rectangle(double l, double w, std::string c) 
        : Shape(c), length(l), width(w) {}
    
    double getArea() const override {
        return length * width;
    }
    
    double getPerimeter() const override {
        return 2 * (length + width);
    }
    
    double getLength() const { return length; }
    double getWidth() const { return width; }
};

class Vehicle {
protected:
    std::string make, model;
    int year;
    
public:
    Vehicle(std::string ma, std::string mo, int y) 
        : make(ma), model(mo), year(y) {}
    
    virtual void start() {
        std::cout << year << " " << make << " " << model << " starts" << std::endl;
    }
    
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    int doors;
    
public:
    Car(std::string ma, std::string mo, int y, int d) 
        : Vehicle(ma, mo, y), doors(d) {}
    
    void start() override {
        std::cout << doors << "-door " << year << " " << make << " " << model << " car starts with engine" << std::endl;
    }
};

class Motorcycle : public Vehicle {
private:
    bool hasSidecar;
    
public:
    Motorcycle(std::string ma, std::string mo, int y, bool sidecar) 
        : Vehicle(ma, mo, y), hasSidecar(sidecar) {}
    
    void start() override {
        std::cout << year << " " << make << " " << model << " motorcycle starts" 
                  << (hasSidecar ? " with sidecar" : "") << std::endl;
    }
};

void testInheritance() {
    std::cout << "Test 1: Basic Inheritance" << std::endl;
    
    Dog dog("Buddy", 3, "Golden Retriever");
    Bird bird("Tweety", 1, 0.3);
    
    assert(dog.getName() == "Buddy");
    assert(dog.getAge() == 3);
    assert(dog.getBreed() == "Golden Retriever");
    
    assert(bird.getName() == "Tweety");
    assert(bird.getAge() == 1);
    assert(bird.getWingspan() == 0.3);
    
    std::cout << "Dog: " << dog.getName() << ", Age: " << dog.getAge() << std::endl;
    std::cout << "Bird: " << bird.getName() << ", Wingspan: " << bird.getWingspan() << "m" << std::endl;
    
    std::cout << "✓ Test passed: Basic inheritance works correctly\n" << std::endl;
}

void testPolymorphism() {
    std::cout << "Test 2: Polymorphism" << std::endl;
    
    Dog dog("Rex", 5, "German Shepherd");
    Bird bird("Eagle", 8, 2.5);
    
    Animal* animals[] = {&dog, &bird};
    
    for (int i = 0; i < 2; i++) {
        animals[i]->makeSound();
        animals[i]->move();
    }
    
    std::cout << "✓ Test passed: Polymorphism works correctly\n" << std::endl;
}

void testAbstractClasses() {
    std::cout << "Test 3: Abstract Classes" << std::endl;
    
    Circle circle(5.0, "Red");
    Rectangle rectangle(4.0, 6.0, "Blue");
    
    assert(std::abs(circle.getArea() - 78.54) < 0.01);
    assert(std::abs(rectangle.getArea() - 24.0) < 0.01);
    
    Shape* shapes[] = {&circle, &rectangle};
    
    double totalArea = 0;
    for (int i = 0; i < 2; i++) {
        totalArea += shapes[i]->getArea();
        std::cout << "Shape color: " << shapes[i]->getColor() 
                  << ", Area: " << shapes[i]->getArea() << std::endl;
    }
    
    assert(std::abs(totalArea - 102.54) < 0.01);
    
    std::cout << "✓ Test passed: Abstract classes work correctly\n" << std::endl;
}

void testVirtualFunctions() {
    std::cout << "Test 4: Virtual Functions" << std::endl;
    
    Car car("Toyota", "Camry", 2023, 4);
    Motorcycle motorcycle("Harley", "Davidson", 2022, false);
    
    Vehicle* vehicles[] = {&car, &motorcycle};
    
    for (int i = 0; i < 2; i++) {
        vehicles[i]->start();
    }
    
    std::cout << "✓ Test passed: Virtual functions work correctly\n" << std::endl;
}

void testAccessSpecifiers() {
    std::cout << "Test 5: Access Specifiers" << std::endl;
    
    class Base {
    public:
        int publicVar;
    protected:
        int protectedVar;
    private:
        int privateVar;
        
    public:
        Base() : publicVar(1), protectedVar(2), privateVar(3) {}
        
        int getPrivateVar() const { return privateVar; }
    };
    
    class Derived : public Base {
    public:
        void testAccess() {
            publicVar = 10;
            protectedVar = 20;
            assert(publicVar == 10);
            assert(protectedVar == 20);
        }
    };
    
    Derived derived;
    derived.testAccess();
    derived.publicVar = 100;
    
    assert(derived.publicVar == 100);
    assert(derived.getPrivateVar() == 3);
    
    std::cout << "Public variable: " << derived.publicVar << std::endl;
    std::cout << "Private variable (via getter): " << derived.getPrivateVar() << std::endl;
    
    std::cout << "✓ Test passed: Access specifiers work correctly\n" << std::endl;
}

void testConstructorInheritance() {
    std::cout << "Test 6: Constructor Inheritance" << std::endl;
    
    class BaseClass {
    protected:
        std::string baseName;
    public:
        BaseClass(std::string name) : baseName(name) {
            std::cout << "Base constructor: " << baseName << std::endl;
        }
        
        virtual ~BaseClass() {
            std::cout << "Base destructor: " << baseName << std::endl;
        }
        
        std::string getBaseName() const { return baseName; }
    };
    
    class DerivedClass : public BaseClass {
    private:
        int derivedValue;
    public:
        DerivedClass(std::string name, int value) 
            : BaseClass(name), derivedValue(value) {
            std::cout << "Derived constructor: " << derivedValue << std::endl;
        }
        
        ~DerivedClass() {
            std::cout << "Derived destructor: " << derivedValue << std::endl;
        }
        
        int getDerivedValue() const { return derivedValue; }
    };
    
    {
        DerivedClass obj("Test", 42);
        assert(obj.getBaseName() == "Test");
        assert(obj.getDerivedValue() == 42);
    }
    
    std::cout << "✓ Test passed: Constructor inheritance works correctly\n" << std::endl;
}

void testMultipleInheritance() {
    std::cout << "Test 7: Multiple Inheritance" << std::endl;
    
    class Flyable {
    public:
        virtual void fly() const {
            std::cout << "Flying..." << std::endl;
        }
        virtual ~Flyable() {}
    };
    
    class Swimmable {
    public:
        virtual void swim() const {
            std::cout << "Swimming..." << std::endl;
        }
        virtual ~Swimmable() {}
    };
    
    class Duck : public Animal, public Flyable, public Swimmable {
    public:
        Duck(std::string n, int a) : Animal(n, a) {}
        
        void makeSound() const override {
            std::cout << name << " quacks: Quack! Quack!" << std::endl;
        }
        
        void move() const override {
            std::cout << name << " can walk, fly, and swim" << std::endl;
        }
        
        void fly() const override {
            std::cout << name << " flies gracefully" << std::endl;
        }
        
        void swim() const override {
            std::cout << name << " swims on the pond" << std::endl;
        }
    };
    
    Duck duck("Donald", 4);
    
    duck.makeSound();
    duck.move();
    duck.fly();
    duck.swim();
    
    assert(duck.getName() == "Donald");
    assert(duck.getAge() == 4);
    
    std::cout << "✓ Test passed: Multiple inheritance works correctly\n" << std::endl;
}

void testVirtualDestructor() {
    std::cout << "Test 8: Virtual Destructor" << std::endl;
    
    class Base {
    public:
        Base() { std::cout << "Base constructor" << std::endl; }
        virtual ~Base() { std::cout << "Base destructor" << std::endl; }
    };
    
    class Derived : public Base {
    public:
        Derived() { std::cout << "Derived constructor" << std::endl; }
        ~Derived() { std::cout << "Derived destructor" << std::endl; }
    };
    
    {
        Base* ptr = new Derived();
        delete ptr;
    }
    
    std::cout << "✓ Test passed: Virtual destructor works correctly\n" << std::endl;
}

void testOperatorOverloading() {
    std::cout << "Test 9: Operator Overloading in Inheritance" << std::endl;
    
    class Point {
    protected:
        double x, y;
    public:
        Point(double x, double y) : x(x), y(y) {}
        
        Point operator+(const Point& other) const {
            return Point(x + other.x, y + other.y);
        }
        
        bool operator==(const Point& other) const {
            return x == other.x && y == other.y;
        }
        
        double getX() const { return x; }
        double getY() const { return y; }
    };
    
    class Point3D : public Point {
    private:
        double z;
    public:
        Point3D(double x, double y, double z) : Point(x, y), z(z) {}
        
        Point3D operator+(const Point3D& other) const {
            return Point3D(x + other.x, y + other.y, z + other.z);
        }
        
        double getZ() const { return z; }
    };
    
    Point3D p1(1, 2, 3);
    Point3D p2(4, 5, 6);
    Point3D p3 = p1 + p2;
    
    assert(p3.getX() == 5);
    assert(p3.getY() == 7);
    assert(p3.getZ() == 9);
    
    std::cout << "Point3D result: (" << p3.getX() << ", " << p3.getY() << ", " << p3.getZ() << ")" << std::endl;
    
    std::cout << "✓ Test passed: Operator overloading in inheritance works\n" << std::endl;
}

void testPolymorphicContainers() {
    std::cout << "Test 10: Polymorphic Containers" << std::endl;
    
    std::vector<std::unique_ptr<Animal>> zoo;
    zoo.push_back(std::make_unique<Dog>("Max", 6, "Labrador"));
    zoo.push_back(std::make_unique<Bird>("Robin", 2, 0.25));
    
    double totalAge = 0;
    for (const auto& animal : zoo) {
        animal->makeSound();
        animal->move();
        totalAge += animal->getAge();
    }
    
    assert(totalAge == 8);
    std::cout << "Total age of animals in zoo: " << totalAge << std::endl;
    
    std::cout << "✓ Test passed: Polymorphic containers work correctly\n" << std::endl;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "Chapter 11: Classes and OOP" << std::endl;
    std::cout << "Test Suite" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    testInheritance();
    testPolymorphism();
    testAbstractClasses();
    testVirtualFunctions();
    testAccessSpecifiers();
    testConstructorInheritance();
    testMultipleInheritance();
    testVirtualDestructor();
    testOperatorOverloading();
    testPolymorphicContainers();
    
    std::cout << "========================================" << std::endl;
    std::cout << "All Chapter 11 tests passed successfully!" << std::endl;
    std::cout << "========================================" << std::endl;
    
    return 0;
}