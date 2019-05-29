/*
Final Written Exam
A program that converts an array into a binary search tree and finds the level a value is on the search tree
Chris Buckey
003146116
02/28/2019
*/

#include <iostream>
using namespace std;  

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST
{
 public:
  /***** Function Members *****/
  BST();
  bool empty() const;
  bool search(const int & item) const; 
  void insert(const int & item);
  void convertarraytoBST(int[], int, int);
  void preOrder();
  int FindLevel(int);
  
 private:
  /***** Node class *****/
  class BinNode 
  {
   public:
    int data;
    BinNode * left;
    BinNode * right;

    // BinNode constructors
    // Default -- data part is default int value; both links are null.
    BinNode()
    : left(0), right(0)
    {}

    // Explicit Value -- data part contains item; both links are null.
    BinNode(int item)
    : data(item), left(0), right(0)
    {}
 

	void getpreOrder(BinNode * node);
	int getLevel(BinNode*, int, int);
  };// end of class BinNode declaration
  
  /***** Data Members *****/
  BinNode * myRoot; 

}; // end of class declaration

#endif
