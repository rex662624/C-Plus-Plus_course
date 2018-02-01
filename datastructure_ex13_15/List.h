#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <new>
#include "ListNode.h"
#include "Package.h" // Package class definition
#include "TwoDayPackage.h" // TwoDayPackage class definition
#include "OvernightPackage.h" // OvernightPackage class definition

using namespace std; 

 template< typename NODETYPE >
 class List
 {
 public:
 List(); // default constructor
 ~List(); // destructor

 void insertAtFront( const NODETYPE & );
 void insertAtBack( const NODETYPE & );
 bool removeFromFront( NODETYPE & );
 bool removeFromBack( NODETYPE & );
 bool isEmpty() const;
 void print() const;
 protected:
 ListNode< NODETYPE > *firstPtr; // pointer to first node
 ListNode< NODETYPE > *lastPtr; // pointer to last node
 // Utility function to allocate a new node
 ListNode< NODETYPE > *getNewNode( const NODETYPE & );
 }; // end class template List

// default constructor
 template< typename NODETYPE >
 List< NODETYPE >::List()
 {
 firstPtr = lastPtr = 0;
 } // end constructor
 
template< typename NODETYPE >
List< NODETYPE >::~List()
{
if ( !isEmpty() ) // List is not empty
 {
 cout << "Destroying nodes ...\n";

ListNode< NODETYPE > *currentPtr = firstPtr;
ListNode< NODETYPE > *tempPtr;

 while ( currentPtr != 0 ) // delete remaining nodes
 {
 tempPtr = currentPtr;
 cout << tempPtr->data << ' ';
 currentPtr = currentPtr->nextPtr;
 delete tempPtr;
 } // end while
 } // end if

 cout << "\nAll nodes destroyed\n\n";
 } // end destructor

 // Insert a node at the front of the list
 template< typename NODETYPE >
 void List< NODETYPE >::insertAtFront( const NODETYPE &value )
 {
 ListNode<NODETYPE> *newPtr = getNewNode( value );

 if ( isEmpty() ) // List is empty
 firstPtr = lastPtr = newPtr;
 else // List is not empty
 {
 newPtr->nextPtr = firstPtr;
 firstPtr = newPtr;
 } // end else
 } // end function insertAtFront

 // Insert a node at the back of the list
 template< typename NODETYPE >
 void List< NODETYPE >::insertAtBack( const NODETYPE &value )
 {
 ListNode< NODETYPE > *newPtr = getNewNode( value );

 if ( isEmpty() ) // List is empty
 firstPtr = lastPtr = newPtr;


else // List is not empty
 {
 lastPtr->nextPtr = newPtr;
 lastPtr = newPtr;
 } // end else
 } // end function insertAtBack

 // Delete a node from the front of the list
 template< typename NODETYPE >
 bool List< NODETYPE >::removeFromFront( NODETYPE &value )
 {
 if ( isEmpty() ) // List is empty
 return false; // delete unsuccessful
 else
 {
 ListNode< NODETYPE > *tempPtr = firstPtr;

 if ( firstPtr == lastPtr )
 firstPtr = lastPtr = 0;
 else
 firstPtr = firstPtr->nextPtr;

 value = tempPtr->data; // data being removed

 delete tempPtr;
 return true; // delete successful
 } // end else
 } // end function removeFromFront

 // delete a node from the back of the list
 template< typename NODETYPE >
 bool List< NODETYPE >::removeFromBack( NODETYPE &value )
 {
 if ( isEmpty() )
 return false; // delete unsuccessful
 else
 {
 ListNode< NODETYPE > *tempPtr = lastPtr;

 if ( firstPtr == lastPtr )
 firstPtr = lastPtr = 0;
 else
 {
 ListNode< NODETYPE > *currentPtr = firstPtr;

 while ( currentPtr->nextPtr != lastPtr )
 currentPtr = currentPtr->nextPtr;

 lastPtr = currentPtr;
 currentPtr->nextPtr = 0;
 } // end else

 value = tempPtr->data;
 delete tempPtr;
 return true; // delete successful

 } // end else
 } // end function removeFromBack

// Is the List empty?
 template< typename NODETYPE >
 bool List< NODETYPE >::isEmpty() const
{
 return firstPtr == 0;
 } // end function isEmpty

 // Return a pointer to a newly allocated node
 template< typename NODETYPE >
 ListNode< NODETYPE > *List< NODETYPE >::getNewNode(
const NODETYPE &value )
 {
 ListNode< NODETYPE > *ptr = new ListNode< NODETYPE >( value );
 return ptr;
 } // end function getNewNode

 // Display the contents of the List
 template< typename NODETYPE >
 void List< NODETYPE >::print() const
{

 if ( isEmpty() ) // empty list
 {
 cout << "The list is empty\n\n";
 return;
 } // end if

 ListNode< NODETYPE > *currentPtr = firstPtr;


 while ( currentPtr != 0 ) // display elements in list
 {
 cout <<*currentPtr->data<<endl<<endl;
 currentPtr = currentPtr->nextPtr;
 } // end while

 cout << "\n\n";
 } // end function print

 #endif

	
