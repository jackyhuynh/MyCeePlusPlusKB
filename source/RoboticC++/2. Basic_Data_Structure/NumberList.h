// Specification file for the NumberList class
#ifndef NUMBERLIST_H
#define NUMBERLIST_H

struct Data
{
    double value;
    // other fields could be added here
};

class NumberList
{
private:
   // Declare a structure for the list
   struct ListNode
   {
      //double value;           // The value in this node
      Data data;
      ListNode *next;  // To point to the next node
   };

   ListNode *head;            // List head pointer

public:
   // Constructor
   NumberList()
      { head = NULL; }

   // Destructor
   ~NumberList();

   // Linked list operations
   void appendNode(Data);   //void appendNode(double);
   void insertNode(Data);   //void insertNode(double);
   void deleteNode(double);
   void displayList() const;

};
#endif
