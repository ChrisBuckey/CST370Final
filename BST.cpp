/*
Final Written Exam
A program that converts an array into a binary search tree and finds the level a value is on the search tree
Chris Buckey
003146116
02/28/2019
*/

#include <iostream>
#include <iomanip>

using namespace std;

#include "BST.h"

//--- Definition of constructor
BST::BST()
: myRoot(0)
{}

bool BST::empty() const
{ return myRoot == 0; }


bool BST::search(const int & item) const
{
   BinNode * locptr = myRoot;
   bool found = false;
   while (!found && locptr != 0)
   {
      if (item < locptr->data)       // descend left
        locptr = locptr->left;
      else if (locptr->data < item)  // descend right
        locptr = locptr->right;
      else                           // item found
        found = true;
   }
   return found;
}


void BST::insert(const int & item)
{
   BinNode * locptr = myRoot;   // search pointer
   BinNode * parent = 0;        // pointer to parent of current node
   bool found = false;     // indicates if item already in BST
   while (!found && locptr != 0)
   {
      parent = locptr;
      if (item < locptr->data)       // descend left
         locptr = locptr->left;
      else if (locptr->data < item)  // descend right
         locptr = locptr->right;
      else                           // item found
         found = true;
   }
   if (!found)
   {                                 // construct node containing item
      locptr = new BinNode(item);  
      if (parent == 0)               // empty tree
         myRoot = locptr;
      else if (item < parent->data )  // insert to left of parent
         parent->left = locptr;
      else                           // insert to right of parent
         parent->right = locptr;
   }
   else
      cout << "Item already in the tree\n";
}

void BST::convertarraytoBST(int array[], int start, int end) {
	if (start > end) {  // end of function
		return;
	}
	else{
		int median = (start + end) / 2;  // find median index of array
		int medianvalue = array[median];  //find that medians value
		BST::insert(medianvalue);  //insert the median as a value into the array (the insert functions figures out the rest)
		cout << medianvalue  << "   ";  // display the value inserted for validation purposes
		BST::convertarraytoBST(array, start, median - 1);  // divide the array in half and insert the values to the left of the array
		BST::convertarraytoBST(array, median + 1, end);  //divide the array in half and insert the values to the right of the array
	}
}


//this is a helper function for FindLevel
int BST::BinNode::getLevel(BinNode *node, int searchvalue, int level = 1){	
	//if found at root
	if (node == NULL)
		return 0;

		// return the level where you found the searchvalue
		if (node->data == searchvalue)
			return level;


		// go down the left subtree until searchvalue is found
		int lowerlevel = getLevel(node->left, searchvalue, level + 1);
		if (lowerlevel != 0)
			return lowerlevel;


		//go down the right subtree until searchvalue is found
		lowerlevel = getLevel(node->right, searchvalue, level + 1);
		return lowerlevel;
}

int BST::FindLevel(int searchvalue) {
	BinNode * locptr = myRoot;
	int level = locptr->getLevel(locptr, searchvalue, 0);
	return level;
}

//public preorder traversal function that uses the private getpreOrder() function
void BST::preOrder() {
	BinNode * locptr = myRoot;
	locptr->getpreOrder(locptr);
}

//display the nodes of a preorder traversal
void BST::BinNode::getpreOrder(BinNode * node) {

	if (node == NULL) {
		return;
	}
	//print data
	cout << node->data << " ";

	//go down left subtree
	getpreOrder(node->left);

	//go down right subtree
	getpreOrder(node->right);
}

int main() {
	BST intBST;

	int samplearray1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int samplearray2[] = { 1,2,3,4,5,6,7,8,9,10,11 };
	int samplearray3[] = { 1 };
	int arraysize = sizeof(samplearray2) / sizeof(*samplearray2);
	
	cout << "Value Inserted ";
	intBST.convertarraytoBST(samplearray2, 0, arraysize - 1);
	cout << endl << endl;
	
	cout << "Preorder Traversal = ";
	intBST.preOrder();

	cout << endl << endl;
	
	for (int i = 0; i < arraysize; i++) {
		cout << "Value " << samplearray2[i] << " found at level " << intBST.FindLevel(samplearray2[i]) << endl;
	}



	return 0;
}