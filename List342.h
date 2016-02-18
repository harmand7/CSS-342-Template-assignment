#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <class ItemType>
class List342
{

	template <class ItemType>
	friend ostream &operator<< <>(std::ostream& out, const List342<ItemType>& list);

public:
	List342();
	List342(const List342 &list);

	bool BuildList(string FileName);
	
	bool Insert(ItemType *obj);
	bool Remove(ItemType target, ItemType &result);
	
	bool Peek(ItemType target, ItemType &result);
	bool isEmpty();
	void DeleteList();
	bool Merge(List342 &list1);

	List342<ItemType>& operator+=(const List342<ItemType> &list);
	List342<ItemType> operator+(const List342<ItemType> &list) const;

	bool operator==(const List342<ItemType> &list) const;
	bool operator!=(const List342<ItemType> &list) const;

	List342<ItemType> operator=(const List342 &list);

	~List342();
	

private:
	struct Node
	{
		ItemType* data;
		Node *next = NULL;
	};
	Node *head;

};


#include <iostream>
#include <string>
#include <fstream>

#include "List342.h"




template <class ItemType>
List342<ItemType>::List342()
{
	head = NULL;
}
template <class ItemType>
List342<ItemType>::List342(const List342 &list)
{
	List342();
	*this = list;
}

template <class ItemType>
bool List342<ItemType>::BuildList(string FileName)
{
	ifstream infile;
	infile.open(FileName);
	if (!infile)
	{
		cout << "The file could not be opened" << endl;
		return false;
	}
	while (!infile.eof())
	{
		ItemType temp;
		infile >> temp;
		Insert(&temp);
	}
	return true;
}
template <class ItemType>
bool List342<ItemType>::Insert(ItemType *obj)
{
	Node *insNode = new Node;
	insNode->data = obj;

	if (isEmpty() || *insNode->data < *head->data)
	{
		insNode->next = head;
		head = insNode;
	}
	else {
		Node* current = head->next;          // to walk list
		Node* previous = head;               // to walk list, lags behind

		// walk until end of the list or found position to insert
		while (current != NULL && *current->data < *insNode->data) {
			previous = current;                  // walk to next node
			current = current->next;
		}

		// insert new node, link it in
		insNode->next = current;
		previous->next = insNode;
	}
	return true;
}

template <class ItemType>
bool List342<ItemType>::Remove(ItemType target, ItemType& result)
{
	Node *current;
	if (isEmpty())
	{
		return false;
	}
	if (*head->data == target)
	{
		current = head;
		head = head->next;
		result = *current->data;
		delete current;
		current = NULL;
		return true;
	}
	Node *previous = head;
	while (previous->next != NULL && *previous->next->data < target)
	{
		previous = previous->next;
	}
	if (previous->next == NULL)
	{
		return false;
	}
	if (*previous->next->data == target)
	{
		current = previous->next;
		result = *current->data;
		previous->next = previous->next->next;
		delete current;
		current = NULL;
		return true;
	}
	return false;
}

template <class ItemType>
bool List342<ItemType>::Peek(ItemType target, ItemType& result)
{
	if (isEmpty())
	{
		return false;
	}
	Node *current;
	current = head;
	while (*current->data != target)
	{
		if (current->next == NULL)
		{
			return false;
		}
		current = current->next;
	}
	result = *current->data;
	return true;
}
template <class ItemType>
bool List342<ItemType>::isEmpty()
{
	return(head == NULL);
}

template <class ItemType>
void List342<ItemType>::DeleteList()
{
	while (head != NULL)
	{
		Node*temp = new Node;
		temp = head;
		head = head->next;
		delete temp;
	}
}

template <class ItemType>
bool List342<ItemType>::Merge(List342<ItemType> &list)
{
	Node *current = head;
	while (list.head != NULL && current != NULL)
	{
		if (current->next == NULL)
		{
			current->next = list.head;
			return true;
		}
		else if (head->data == list.head->data)
		{
			Node *temp = list.head;
			list.head = list.head->next;
			delete temp;
		}
		else if (head->data > list.head->data)
		{
			head = list.head;
			list.head = list.head->next;
			head->next = current;
			current = head;
		}
		else if (current->next->data == list.head->data)
		{
			Node *temp = current->next;
			//delete list ptr
			temp = list.head;
			list.head = list.head->next;
			delete temp;
		}
		else if (current->next->data > list.head->data)
		{
			Node *temp = current->next;
			current->next = list.head;
			list.head = list.head->next;
			current = current->next;
			current->next = temp;
		}
		else
		{
			current = current->next;
		}
	}
}

template <class ItemType>
List342<ItemType>& List342<ItemType>::operator+=(const List342<ItemType> &list)
{
	List342<ItemType> temp = list;
	this->Merge(temp);
	return *this;
}
template <class ItemType>
List342<ItemType> List342<ItemType>::operator+(const List342<ItemType> &list) const
{
	List342 temp = *this;
	List342 temp2 = list;
	temp.Merge(temp2);
	return temp;
}

template <class ItemType>
bool List342<ItemType>::operator==(const List342<ItemType> &list) const
{
	Node *rhs, *lhs;
	lhs = head;
	rhs = list.head;
	while (rhs->data == lhs->data)
	{
		if (rhs->next == NULL && lhs->next == NULL)
		{
			return true;
		}
		if (rhs->next != NULL && lhs->next == NULL)
		{
			return false;
		}
		if (rhs->next == NULL && lhs->next != NULL)
		{
			return false;
		}
		rhs = rhs->next;
		lhs = lhs->next;
	}
	return false;
}

template <class ItemType>
bool List342<ItemType>::operator!=(const List342<ItemType> &list) const
{
	return!(*this == list);
}

template <class ItemType>
List342<ItemType> List342<ItemType>::operator=(const List342<ItemType> &list)
{
	Node *sNode, *dNode, *insNode;
	if (this == &list)
	{
		return *this;
	}
	this->DeleteList();
	if (list.head == NULL)
	{
		return *this;
	}
	dNode = new Node;
	dNode->data = list.head->data;
	this->head = dNode; 
	sNode = list.head->next;
	while (sNode != NULL)
	{
		insNode = new Node;
		insNode->data = sNode->data;
		dNode->next = insNode;
		dNode = dNode->next;
		sNode = sNode->next;
	}
	return *this;
}
template <class ItemType>
ostream &operator<<(ostream& out, const List342<ItemType>& thelist)
{
	List342<ItemType>::Node* current = thelist.head;
	while (current != NULL)
	{
		ItemType temp = *(current->data);
		out << temp;
		current = current->next;
	}
	return out;
}
template <class ItemType>
List342<ItemType>::~List342()
{
	this->DeleteList();
}
