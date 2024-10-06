// This program demonstrates the displayList member function.
#include <iostream>
#include "NumberList.h"
using namespace std;

int main()
{
   // Define a NumberList object.
   NumberList list;
   Data a[10] = {{2.5}, {7.9}, {12.6}};

   // Append some values to the list.
   list.appendNode(a[1]);
   list.appendNode(a[2]);
   list.appendNode(a[0]);

   // Display the values in the list.
   list.displayList();
   return 0;
}
