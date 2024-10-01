#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>
using namespace std;
using namespace boost;

enum class Color {red, green, blue};
enum class Size {small, medium, large};

struct Product
{
    string name; 
    Color color;
    Size size;
}

struct ProductFilter