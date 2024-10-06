# Airthmetic Operation

## Introduction:

Arithmetic operations in C++ are similar to other languages. We’ll have a quick discussion about them here and then you can practice programming (+, -, *, /, %)

```
/*Goal: practice arithmetic operations in C++
**Write a program that calculates the volumes of:
**a cube, sphere, cone.
**Cube Volume = side^3
**Sphere Volume = (4/3) * pi * radius^3
**Cone Volume = pi * radius^2 * (height/3)
**Write the values to the console.
*/

#include<iostream>

int main()
{
    //Dimension of the cube
    float cubeSide = 5.4;
    //Dimension of sphere
    float sphereRadius = 2.33;
    //Dimensions of cone
    float coneRadius = 7.65;
    float coneHeight = 14;
    
    float volCube, volSphere, volCone = 0;
    
    //find volume of cube
     volCube = std::pow(cubeSide, 3);
    //find volume of sphere
    volSphere = (4.0/3.0)*M_PI*std::pow(sphereRadius,3);
    //find volume of cone
    //M_PI is in the cmath library, it does not need to reference the
    //std namespace. On the other hand, pow() needs to reference it.
    volCone = M_PI * std::pow(coneRadius, 2) * (coneHeight/3);
    std::cout <<"\nVolume of Cube: "<<volCube<<"\n";
    std::cout <<"\nVolume of Sphere: "<<volSphere<<"\n";
    std::cout <<"\nVolume of Cone: "<<volCone<<"\n";

    return 0;
}
```

## Implicit conversions

C++ is a language that requires variable types to be known at compile time.

But, C++ does allow some implicit conversions, for example an integer can be assigned to a float or an integer can be treated as a char.

## Prefix vs. Postfix

In C++, as in many languages, there are postfix and prefix operators.
The form for each is:

Incrementing

prefix: ++a
postfix: a++
Decrementing

prefix: --a
postfix: a--
The difference between prefix and postfix is subtle, but crucial.

Prefix operators increment the value of the variable, then return the reference to the variable.

Postfix operators create a copy of the variable and increments the value of the variable. Then it returns a copy from BEFORE the increment.

As you can read in the Increment and Decrement documentation

increment and decrement operators can result in violations of sequencing.

## Assignment Operator

As with other programming languages, C++ allows assignment operators.
The table below shows the most often used assignment operators supported by C++.

## Control Flow

C++ has several control flow options.

- if-else statements
- for loops
- while loops
- switch statements