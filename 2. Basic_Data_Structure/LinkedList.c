/*	Test driver for list functions.
	   Written by:
	   Date:
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//	Global Declarations
typedef struct
{
    int key;  // THIS MUST BE CHANGED

}   DATA;  // DATA IS A GENERIC NAME - change it to STU to be specific
typedef struct nodeTag
{
    DATA            data;  // change data to stu to be specific
    struct nodeTag* link;
} NODE;

//	Function Declarations
NODE* insertNode (NODE*  pList, NODE*  pPre, DATA  item);
NODE* deleteNode (NODE*  List,  NODE*  pPre, NODE* pCur);
bool  searchList (NODE*  pList, NODE**   pPre,
                  NODE** pCur,  int target);
void  printList  (NODE*  pList);
NODE* buildList  (char*  fileID);
NODE* deleteKey  (NODE*  pList);
bool  getData    (FILE*  fpData, DATA* pData);

double averageList (NODE* pList);

//	Header file to include functions (Not in text)
//#include "P15-LIST.H"

int main (void)
{
//	Local Declarations
	NODE*  pList;
	NODE*  pPre;
	NODE*  pCur;
	DATA   data;
	double avrg;
	char   more;

//	Statements
	printf("Begin list test driver\n\n");

	//	Build List
	pList = buildList("P15-LIST.TXT");
	if (!pList)
    {
	    printf("Error building chron file\a\n");
	    exit  (100);
	} // if
	printList (pList);

	printf("\nInsert data tests.\n");
	printf("Enter key:              ");
	scanf ("%d", &data.key);
	do
	{
	    if (searchList (pList, &pPre, &pCur, data.key))
	        printf("Key already in list. Not inserted\n");
	    else
	        pList = insertNode(pList, pPre, data);
	    printf("Enter key <-1> to stop: ");
	    scanf ("%d", &data.key);
	} while (data.key != -1);
	printList (pList);

	avrg = averageList(pList);
	printf("\nData average: %.1f\n", avrg);

	printf("\nDelete data tests.\n");
	do
	{
	    pList = deleteKey (pList);
	    printf("Delete another <Y/N>: ");
	    scanf (" %c", &more);
	} while (more == 'Y' || more == 'y');

	printList (pList);
	printf("\nTests complete.\n");
	return 0;
} // main
/*	==================== insertNode ====================
	This function inserts a single node into a linear list.
	   Pre   pList is pointer to the list; may be null
	         pPre points to new node’s predecessor
	         item contains data to be inserted
	   Post  returns the head pointer
*/
NODE* insertNode (NODE* pList, NODE* pPre, DATA item)
{
//	Local Declarations
	NODE* pNew;

//	Statements
	if (!(pNew  = (NODE*)malloc(sizeof(NODE))))
	    printf("\aMemory overflow in insert\n"), exit (100);

	pNew->data = item;
	if (pPre == NULL)
    {
	    // Inserting before first node or to empty list
	    pNew->link  = pList;
	    pList       = pNew;
	} // if pPre
	else
	{
	    // Inserting in middle or at end
	    pNew->link = pPre->link;
	    pPre->link = pNew;
	} // else
	return pList;
}	// insertNode

/*	==================== deleteNode ====================
	This function deletes a single node from the link list.
	   Pre   pList is a pointer to the head of the list
	         pPre points to node before the delete node
	         pCur points to the node to be deleted
	   Post  deletes and recycles pCur
	         returns the head pointer
*/
NODE* deleteNode (NODE* pList, NODE* pPre, NODE* pCur)
{
//	Statements
	if (pPre == NULL)
	   // Deleting first node
	   pList = pCur->link;
	else
	   // Deleting other nodes
	   pPre->link = pCur->link;
	free  (pCur);
	return pList;
}	// deleteNode

/*	==================== searchList ====================
	Given key value, finds the location of a node
	   Pre   pList points to a head node
	         pPre points to variable to receive pred
	         pCur points to variable for current node
	         target is key being sought
	   Post  pCur points to first node with >= key
	         -or- null if target > key of last node
	         pPre points to largest node < than key
	         -or- null if target < key of first node
	         function returns true if found
	                          false if not found
*/
bool searchList (NODE*  pList, NODE**   pPre,
                 NODE** pCur,  int target)
{
//	Local Declarations
	bool found = false;

//	Statements
	*pPre = NULL;
	*pCur = pList;

	// start the search from beginning
	while (*pCur != NULL && target > (*pCur)->data.key)
	{
	    *pPre = *pCur;
	    *pCur = (*pCur)->link;
	} // while

	if (*pCur != NULL && target == (*pCur)->data.key)
	   found = true;
	return found;
}	// searchList

/*	Traverse and print a linear list.
	   Pre   pList is a valid linear list
	   Post  List has been printed
*/
void printList (NODE* pList)
{
//	Local Declarations
	NODE* pWalker;

//	Statements
	pWalker = pList;
	printf("List contains:\n");

	while (pWalker)
	{
	    printf("%3d ", pWalker->data.key);
	    pWalker = pWalker->link;
	} // while
	printf("\n");
	return;
} // printList

/*	This function averages the values in a linear list.
	   Pre   pList is a pointer to a linear list
	   Post  list average is returned
*/
double averageList (NODE* pList)
{
//	Local Declarations
	NODE* pWalker;
	int   total;
	int   count;

//	Statements
	total   = count = 0;
	pWalker = pList;
	while (pWalker)
	{
	    total += pWalker->data.key;
	    count++;
	    pWalker = pWalker->link;
	} // while
	return (double)total / count;
} // averageList

/*	==================== buildList ====================
	This program builds a key-sequenced linear list.
	   Pre   fileID is file that contains data for list
	   Post  list built
	         returns pointer to head of list
*/
NODE* buildList (char* fileID)
{
//	Local Declarations
	DATA  data;
	NODE* pList;
	NODE* pPre;
	NODE* pCur;
	FILE* fpData;

//	Statements
	pList = NULL;

	fpData = fopen(fileID, "r");
	if (!fpData)
	{
	    printf("Error opening file %s\a\n", fileID);
	    exit (210);
	} // if open fail

	while (getData (fpData, &data))
	{
	    // Determine insert position
	    searchList (pList, &pPre, &pCur, data.key);
	    pList = insertNode(pList, pPre, data);
	} // while
	return pList;
} // buildList

/*	==================== deleteKey ====================
	Delete node from a linear list.
	   Pre   list is a pointer to the head of the list
	   Post  node has been deleted
	         -or- a warning message printed if not found
	         returns pointer to first node (pList)
*/

NODE* deleteKey (NODE* pList)
{
//	Local Declarations
	int   key;
	NODE* pCur;
	NODE* pPre;

//	Statements
	printf("Enter key of node to be deleted: ");
	scanf ("%d", &key);

	if (!searchList(pList, &pPre, &pCur, key))
	    printf("%d is an invalid key\a\n", key);
	else
	    pList = deleteNode (pList, pPre, pCur);

	return pList;
} // deleteKey

/*	==================== getData ====================
	Reads data from file.
	   Pre   fpData is an open file
	         pData is pointer to input structure
	   Post  data read
             returns success/failure
*/

bool getData (FILE* fpData, DATA* pData)
{
//	Local Definitions
	int ioResult;

//	Statements
	ioResult = fscanf (fpData, "%d", &(pData->key));
	return ioResult == 1;
}	// getData
