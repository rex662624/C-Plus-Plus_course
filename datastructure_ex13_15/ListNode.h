#ifndef LISTNODE_H
#define LISTNODE_H
#include "Package.h" // Package class definition
#include "TwoDayPackage.h" // TwoDayPackage class definition
#include "OvernightPackage.h" // OvernightPackage class definition

	template<typename NODETYPE>class List;

	template<typename NODETYPE>
	class ListNode
	{	
	friend class List<NODETYPE>;
		
	public:
	
		ListNode(const NODETYPE &);
		NODETYPE getdata()const; 
	
	
	private:
	
	NODETYPE data;
	ListNode<NODETYPE>*nextPtr;
		
	};
	
	template<typename NODETYPE>
	ListNode<NODETYPE>::ListNode(const NODETYPE & info)
	:data(info),nextPtr(0)
	{
		
	}
	
	template<typename NODETYPE>
	NODETYPE ListNode<NODETYPE>::getdata()const 
	{
		return data;	
	}
	
	#endif
