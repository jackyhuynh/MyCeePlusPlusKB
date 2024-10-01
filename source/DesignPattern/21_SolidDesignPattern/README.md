# Solid Design Pattern

## Tech
- `namespace boost`
- `boost::lexical_cast`
- `const string& filename`, the expression represents a **constant reference** to a `string` object in C++. Passing a `const string&` avoids copying and modify the `string` object.

## Definition:
### **Journal.cpp**:
- Seperation of concern principle (Journal.md): Make each class handle only onething. Journal responsible for journal and Persistence-Manager take care of saving
- Open Close Principle (FilterProduct.cpp):
